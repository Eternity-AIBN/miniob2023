#pragma once

#include "sql/operator/physical_operator.h"

/**
 * @brief 选择/投影物理算子
 * @ingroup PhysicalOperator
 */
class ProjectAggPhysicalOperator : public PhysicalOperator
{
public:
  ProjectAggPhysicalOperator()
  {}

  virtual ~ProjectAggPhysicalOperator() = default;

  void add_expressions(std::vector<std::unique_ptr<Expression>> &&expressions)
  {
    
  }
  void add_projection(const Table *table, const FieldMeta *field);

  void set_aggop(std::vector<AggOp> aggop)
  {
    aggop_ = aggop;
  }

  void set_select_count_star(std::vector<bool> select_count_star)
  {
    select_count_star_ = select_count_star;
  }

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::PROJECT_AGG;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  int cell_num() const
  {
    return tuple_.cell_num();
  }

  Tuple *current_tuple() override;

private:
  ProjectTuple tuple_;
  ValueListTuple res_tuple;
  std::vector<AggOp> aggop_;
  std::vector<bool> select_count_star_;
};
