#pragma once

#include "sql/operator/logical_operator.h"
#include "sql/expr/expression.h"

class OrderByStmt;

/**
 * @brief 排序(order-by)逻辑算子
 * @ingroup LogicalOperator
 */
class SortLogicalOperator : public LogicalOperator 
{
public:
  SortLogicalOperator(OrderByStmt *orderby_stmt) : orderby_stmt_(orderby_stmt)
  {}
  virtual ~SortLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::SORT;
  }

  OrderByStmt *orderby_stmt_ = nullptr;
};
