#pragma once

#include <memory>
#include "sql/operator/physical_operator.h"
#include "sql/expr/expression.h"

class OrderByStmt;

/**
 * @brief 排序物理算子
 * @ingroup PhysicalOperator
 */
class SortPhysicalOperator : public PhysicalOperator
{
public:
  SortPhysicalOperator(OrderByStmt *orderby_stmt) : orderby_stmt_(orderby_stmt)
  {}
  
  // virtual ~SortPhysicalOperator() = default;
  virtual ~SortPhysicalOperator()
  {
    for (auto &cpd_rcd : sort_table_) {
      for (auto rcd : cpd_rcd) {
        delete rcd;
      }
    }
  }

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::SORT;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

  RC fetch_and_sort_table();

private:
  // std::unique_ptr<Expression> expression_;
  OrderByStmt *orderby_stmt_ = nullptr;
  bool is_first_ = true;

  std::vector<std::vector<Record *>> sort_table_;  // sort table
  std::vector<int> ordered_idx_;
  std::vector<int>::iterator it_;
};
