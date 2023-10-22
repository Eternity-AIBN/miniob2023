#pragma once

#include <vector>
#include <memory>

#include "sql/operator/logical_operator.h"
#include "sql/expr/expression.h"
#include "storage/field/field.h"

/**
 * @brief project_agg 表示投影运算+聚合函数处理
 * @ingroup LogicalOperator
 * @details 从表中获取数据后，可能需要过滤，投影，连接等等。
 */
class ProjectAggLogicalOperator : public LogicalOperator 
{
public:
  ProjectAggLogicalOperator(const std::vector<Field> &fields, const std::vector<AggOp> &aggop);
  virtual ~ProjectAggLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::PROJECTION_AGG;
  }

  std::vector<std::unique_ptr<Expression>> &expressions()
  {
    return expressions_;
  }
  const std::vector<std::unique_ptr<Expression>> &expressions() const
  {
    return expressions_;
  }
  const std::vector<Field> &fields() const
  {
    return fields_;
  }
  const std::vector<AggOp> &aggop() const
  {
    return aggop_;
  }

private:
  //! 投影映射的字段名称
  //! 并不是所有的select都会查看表字段，也可能是常量数字、字符串，
  //! 或者是执行某个函数。所以这里应该是表达式Expression。
  //! 不过现在简单处理，就使用字段来描述
  std::vector<Field> fields_;
  std::vector<AggOp> aggop_;
};
