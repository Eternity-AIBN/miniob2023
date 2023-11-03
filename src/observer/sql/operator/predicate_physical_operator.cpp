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
#include "sql/operator/predicate_physical_operator.h"
#include "storage/record/record.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/field/field.h"

PredicatePhysicalOperator::PredicatePhysicalOperator(std::unique_ptr<Expression> expr) : expression_(std::move(expr))
{
  ASSERT(expression_->value_type() == BOOLEANS, "predicate's expression should be BOOLEAN type");
}


RC PredicatePhysicalOperator::open(Trx *trx)
{
  if (children_.size() != 1) {
    LOG_WARN("predicate operator must has one child");
    return RC::INTERNAL;
  }
  tmp_trx = trx;

  if(ConjunctionExpr* conjunction_expr = dynamic_cast<ConjunctionExpr*>(expression_.get())){
    for (int i=0; i<conjunction_expr->children().size(); i++){
      if(ComparisonExpr* comparison_expr = dynamic_cast<ComparisonExpr*>(conjunction_expr->children()[i].get())){
        if(SubQueryExpression* sub_query_expr = dynamic_cast<SubQueryExpression*>(comparison_expr->right().get())){
          sub_query_expr->gen_physical_plan_for_subquery();
        } 
        if(SubQueryExpression* sub_query_expr = dynamic_cast<SubQueryExpression*>(comparison_expr->left().get())){
          sub_query_expr->gen_physical_plan_for_subquery();
        } 
      }
    }
  } else if(ComparisonExpr* comparison_expr = dynamic_cast<ComparisonExpr*>(expression_.get())){
    if(SubQueryExpression* sub_query_expr = dynamic_cast<SubQueryExpression*>(comparison_expr->right().get())){
      sub_query_expr->gen_physical_plan_for_subquery();
    }
    if(SubQueryExpression* sub_query_expr = dynamic_cast<SubQueryExpression*>(comparison_expr->left().get())){
      sub_query_expr->gen_physical_plan_for_subquery();
    } 
  }

  return children_[0]->open(trx);
}

RC PredicatePhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  PhysicalOperator *oper = children_.front().get();

  while (RC::SUCCESS == (rc = oper->next())) {
    Tuple *tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }

    Value value;
    rc = expression_->get_value(*tuple, value, tmp_trx);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (value.get_boolean()) {
      return rc;
    }
  }
  return rc;
}

RC PredicatePhysicalOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

Tuple *PredicatePhysicalOperator::current_tuple()
{
  return children_[0]->current_tuple();
}
