#pragma once

#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

/**
 * @brief 更新逻辑算子
 * @ingroup LogicalOperator
 */
class UpdateLogicalOperator : public LogicalOperator
{
public:
  UpdateLogicalOperator(Table *table, std::vector<Value> values, std::vector<std::string> attribute_name);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }

  Table *table() const { return table_; }
  // Value values() { return values_; }
  // std::string &attribute_name() { return attribute_name_; }
  std::vector<Value> &values() { return values_; }
  std::vector<std::string> &attribute_name() { return attribute_name_; }

private:
  Table *table_ = nullptr;
  // Value values_;
  // std::string attribute_name_;
  std::vector<Value> values_;
  std::vector<std::string> attribute_name_;
};