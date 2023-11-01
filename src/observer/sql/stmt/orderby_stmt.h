#pragma once

#include <vector>
#include <memory>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class Db;
class Table;
class FieldMeta;

class OrderByUnit {
public:
  OrderByUnit() = default;
  ~OrderByUnit()
  {
    if (expr_) {
      // delete expr_;
      expr_ = nullptr;
    }
  }

  void set_sort_type(bool sort_type)
  {
    is_asc_ = sort_type;
  }

  bool sort_type() const
  {
    return is_asc_;
  }
  void set_expr(Expression *expr)
  {
    expr_ = expr;
  }
  Expression *expr() const
  {
    return expr_;
  }

private:
  // sort type : true is asc
  bool is_asc_ = true;
  Expression *expr_ = nullptr;
};

class OrderByStmt {
public:
  OrderByStmt() = default;
  virtual ~OrderByStmt();

public:
  const std::vector<OrderByUnit *> &orderby_units() const
  {
    return orderby_units_;
  }

public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const OrderByNode *orderbys, int orderby_num, OrderByStmt *&stmt);

  // the func used for creating orderby_stmt for groupby
//   static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
//       const GroupBy *groupbys, int groupby_num, OrderByStmt *&stmt);

  static RC create_orderby_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const OrderByNode &orderby, OrderByUnit *&orderby_unit);

//   static RC create_orderby_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
//       const GroupBy &groupby, OrderByUnit *&orderby_unit);

private:
  std::vector<OrderByUnit *> orderby_units_;
};
