/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/07/08.
//

#include "sql/operator/index_scan_physical_operator.h"
#include "storage/index/index.h"
#include "storage/trx/trx.h"
#include "sql/expr/expression.h"

class ComparisonExpr;

IndexScanPhysicalOperator::IndexScanPhysicalOperator(
    Table *table, Index *index, bool readonly, 
    const Value *left_value, bool left_inclusive, 
    const Value *right_value, bool right_inclusive)
    : table_(table), 
      index_(index), 
      readonly_(readonly), 
      left_inclusive_(left_inclusive), 
      right_inclusive_(right_inclusive)
{
  if (left_value) {
    left_value_ = *left_value;
  }
  if (right_value) {
    right_value_ = *right_value;
  }
}

RC IndexScanPhysicalOperator::open(Trx *trx)
{
  if (nullptr == table_ || nullptr == index_) {
    return RC::INTERNAL;
  }

  // ComparisonExpr
  // 暂时只考虑left都是FieldExpr，而right为ValueExpr
  // const char *left;
  // const char *right;
  int left_len = 0;
  int right_len = 0;
  int value_len = 0;
  int bitmap_len = table_->table_meta().null_bitmap_field()->len();    
  for (int i = 0; i < index_->index_meta().field().size(); i++) {
    string tmp = index_->index_meta().field()[i];
    const char *field_name = tmp.c_str();
    value_len += table_->table_meta().field(field_name)->len();
  }

  char *left = new char[value_len + bitmap_len];
  char *right = new char[value_len + bitmap_len];

  int tmp_length = 0;
  for (int i = predicates_.size()-1; i >=0 ; i--){
    ComparisonExpr* comparisonExpr = static_cast<ComparisonExpr *>(predicates_[i].get());
    ValueExpr* valueExpr = static_cast<ValueExpr *>(comparisonExpr->right().get());
    Value cur_value = valueExpr->get_value();
    if (nullptr != cur_value.data()) {
      tmp_length += cur_value.length();
    }
  }
  memset(left + tmp_length, 0, bitmap_len);
  memset(right + tmp_length, 0, bitmap_len);
  left_len += bitmap_len;
  right_len += bitmap_len;

  int pos = 0;
  for (int i = predicates_.size()-1; i >=0 ; i--){
    ComparisonExpr* comparisonExpr = static_cast<ComparisonExpr *>(predicates_[i].get());
    ValueExpr* valueExpr = static_cast<ValueExpr *>(comparisonExpr->right().get());
    Value cur_value = valueExpr->get_value();
    if (nullptr != cur_value.data()) {
      // set bitmap for null
      common::Bitmap left_map(left + tmp_length, bitmap_len);
      common::Bitmap right_map(right + tmp_length, bitmap_len);
      if (cur_value.attr_type() == AttrType::NULLS) {
        FieldExpr* fieldExpr = static_cast<FieldExpr *>(comparisonExpr->left().get());
        int field_id = fieldExpr->field().meta()->id();
        left_map.set_bit(field_id);
        right_map.set_bit(field_id);
      }

      memcpy(left + pos, cur_value.data(), cur_value.length());
      left_len += cur_value.length();

      memcpy(right + pos, cur_value.data(), cur_value.length());
      right_len += cur_value.length();
      pos += cur_value.length();
    } else {
      left = nullptr;
      left_len = value_len;

      right = nullptr;
      right_len = value_len;
    }
  }

  // id和col1两列组合索引，如果查询条件只有id的情况
  if(predicates_.size() != index_->index_meta().field().size()){    // index_meta().field().size() 是指组合索引有多少列，不包括bitmap
    left[pos+bitmap_len] = 1;
    right[pos+bitmap_len] = 1;
  }

  IndexScanner *index_scanner =
      index_->create_scanner(left, left_len, left_inclusive_, right, right_len, right_inclusive_);

  // IndexScanner *index_scanner = index_->create_scanner(left_value_.data(),
  //     left_value_.length(),
  //     left_inclusive_,
  //     right_value_.data(),
  //     right_value_.length(),
  //     right_inclusive_);
  if (nullptr == index_scanner) {
    LOG_WARN("failed to create index scanner");
    return RC::INTERNAL;
  }

  record_handler_ = table_->record_handler();
  if (nullptr == record_handler_) {
    LOG_WARN("invalid record handler");
    index_scanner->destroy();
    return RC::INTERNAL;
  }
  index_scanner_ = index_scanner;

  tuple_.set_schema(table_, table_->table_meta().field_metas());

  trx_ = trx;
  return RC::SUCCESS;
}

RC IndexScanPhysicalOperator::next()
{
  RID rid;
  RC rc = RC::SUCCESS;

  record_page_handler_.cleanup();

  bool filter_result = false;
  while (RC::SUCCESS == (rc = index_scanner_->next_entry(&rid))) {
    rc = record_handler_->get_record(record_page_handler_, &rid, readonly_, &current_record_);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    tuple_.set_record(&current_record_);
    rc = filter(tuple_, filter_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (!filter_result) {
      continue;
    }

    rc = trx_->visit_record(table_, current_record_, readonly_);
    if (rc == RC::RECORD_INVISIBLE) {
      continue;
    } else {
      return rc;
    }
  }

  return rc;
}

RC IndexScanPhysicalOperator::close()
{
  index_scanner_->destroy();
  index_scanner_ = nullptr;
  return RC::SUCCESS;
}

Tuple *IndexScanPhysicalOperator::current_tuple()
{
  tuple_.set_record(&current_record_);
  return &tuple_;
}

void IndexScanPhysicalOperator::set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs)
{
  predicates_ = std::move(exprs);
}

RC IndexScanPhysicalOperator::filter(RowTuple &tuple, bool &result)
{
  RC rc = RC::SUCCESS;
  Value value;
  for (std::unique_ptr<Expression> &expr : predicates_) {
    rc = expr->get_value(tuple, value);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool tmp_result = value.get_boolean();
    if (!tmp_result) {
      result = false;
      return rc;
    }
  }

  result = true;
  return rc;
}

std::string IndexScanPhysicalOperator::param() const
{
  return std::string(index_->index_meta().name()) + " ON " + table_->name();
}
