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
  // UpdateLogicalOperator(Table *table, std::vector<Value> values, std::vector<std::string> attribute_name);
  UpdateLogicalOperator(Table *table, std::vector<Expression *> &exprs, std::vector<const FieldMeta *> &fields, std::vector<std::string> &attribute_name);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }

  Table *table() const { return table_; }
  // Value values() { return values_; }
  // std::string &attribute_name() { return attribute_name_; }
  // std::vector<Value> &values() { return values_; }
  std::vector<Expression *> &exprs() { return exprs_; }
  std::vector<std::string> &attribute_name() { return attribute_name_; }

public:
  std::vector<const FieldMeta *> fields_;       // 把要更新的字段类型保存下来，后在operator中就不用再判断了
  
private:
  Table *table_ = nullptr;
  // Value values_;
  // std::string attribute_name_;
  // std::vector<Value> values_;
  std::vector<Expression *> exprs_;
  std::vector<std::string> attribute_name_;
};