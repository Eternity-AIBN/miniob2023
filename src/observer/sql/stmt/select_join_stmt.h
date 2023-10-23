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
class SelectJoinStmt : public Stmt 
{
public:
  SelectJoinStmt() = default;
  ~SelectJoinStmt() override;

  StmtType type() const override
  {
    return StmtType::SELECT_JOIN;
  }

public:
  static RC create(Db *db, const SelectJoinSqlNode &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const
  {
    return tables_;
  }
  const std::vector<Field> &query_fields() const
  {
    return query_fields_;
  }
  FilterStmt *filter_stmt() const
  {
    return filter_stmt_;
  }
  FilterStmt *filter_stmt_join() const
  {
    return filter_stmt_join_;
  }

private:
  std::vector<Field> query_fields_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;
  FilterStmt *filter_stmt_join_ = nullptr;
};
