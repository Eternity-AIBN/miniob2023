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
// Created by WangYunlai on 2022/6/27.
//

#include "common/log/log.h"
#include "sql/operator/delete_physical_operator.h"
#include "storage/record/record.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/operator/index_scan_physical_operator.h"
#include "sql/operator/predicate_physical_operator.h"
#include "storage/index/bplus_tree_index.h"

RC DeletePhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  std::unique_ptr<PhysicalOperator> &child = children_[0];
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  return RC::SUCCESS;
}

RC DeletePhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  PhysicalOperator *child = children_[0].get();

  bool delete_index = false;
  bool delete_index2 = false;
  if (IndexScanPhysicalOperator* derived = dynamic_cast<IndexScanPhysicalOperator*>(children_[0].get())){
    delete_index = true;
    // printf("delete_index\n");
  }
  if (PredicatePhysicalOperator* derived = dynamic_cast<PredicatePhysicalOperator*>(children_[0].get())){
    if (IndexScanPhysicalOperator* derived2 = dynamic_cast<IndexScanPhysicalOperator*>(derived->children()[0].get())){
      delete_index2 = true;
      // printf("delete_index2\n");
    }
  }

  while (RC::SUCCESS == (rc = child->next())) {
    printf("child->next()\n");
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record &record = row_tuple->record();
    rc = trx_->delete_record(table_, record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    }
    if(delete_index){
      IndexScanPhysicalOperator* tmp = static_cast<IndexScanPhysicalOperator*>(child);
      BplusTreeIndexScanner *btree_index = static_cast<BplusTreeIndexScanner*>(tmp->get_index_scanner());
      BplusTreeScanner *btree_scan = btree_index->get_tree_scanner_();
      btree_scan->set_iter_index(-1);  //本来是多少就得是多少，不能都为-1，所以改为减去1就行
    }
    if(delete_index2){
      PredicatePhysicalOperator* tt = static_cast<PredicatePhysicalOperator*>(child);
      IndexScanPhysicalOperator* tmp = static_cast<IndexScanPhysicalOperator*>(tt->children()[0].get());
      BplusTreeIndexScanner *btree_index = static_cast<BplusTreeIndexScanner*>(tmp->get_index_scanner());
      BplusTreeScanner *btree_scan = btree_index->get_tree_scanner_();
      btree_scan->set_iter_index(-1);  //本来是多少就得是多少，不能都为-1，所以改为减去1就行
    }
  }

  return RC::RECORD_EOF;
}

RC DeletePhysicalOperator::close()
{
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}
