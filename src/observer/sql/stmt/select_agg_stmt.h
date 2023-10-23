#pragma once

#include <vector>
#include <memory>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

/**
 * @brief 表示select语句
 * @ingroup Statement
 */
class SelectAggStmt : public Stmt 
{
public:
  SelectAggStmt() = default;
  ~SelectAggStmt() override;

  StmtType type() const override
  {
    return StmtType::SELECT_AGG;
  }

public:
  static RC create(Db *db, const SelectAggSqlNode &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const
  {
    return tables_;
  }
  const std::vector<Field> &query_fields() const
  {
    return query_fields_;
  }
  // const std::vector<Field> &query_fields_show() const
  // {
  //   return query_fields_show_;
  // }
  FilterStmt *filter_stmt() const
  {
    return filter_stmt_;
  }
  const std::vector<AggOp> &aggop() const
  {
    return aggop_;
  }
  const std::vector<bool> &select_count_star() const
  {
    return select_count_star_;
  }

private:
  std::vector<Field> query_fields_;
  // std::vector<Field> query_fields_show_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;
  std::vector<AggOp> aggop_;
  std::vector<bool> select_count_star_;
};
