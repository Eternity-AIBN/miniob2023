#include "sql/stmt/select_agg_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

SelectAggStmt::~SelectAggStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas, std::vector<Field> &field_metas_show)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  // for (int i = table_meta.sys_field_num(); i < field_num; i++) {
  //   field_metas.push_back(Field(table, table_meta.field(i)));
  // }
  // select * 才需要将*展开，select count(*) 结果只会有一列
  field_metas.push_back(Field(table, table_meta.field(table_meta.sys_field_num())));
  field_metas_show.push_back(Field(table, nullptr));
}

RC SelectAggStmt::create(Db *db, const SelectAggSqlNode &select_sql, Stmt *&stmt)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  std::vector<AggOp> aggop;
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    const char *table_name = select_sql.relations[i].c_str();
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
  }

  // collect query fields in `select` statement
  std::vector<Field> query_fields;
  std::vector<Field> query_fields_show;
  for (int i = static_cast<int>(select_sql.agg_attributes.size()) - 1; i >= 0; i--) {
    const AggRelAttrSqlNode &relation_attr = select_sql.agg_attributes[i];

    aggop.push_back(relation_attr.agg_func);

    if (common::is_blank(relation_attr.relation_name.c_str()) &&
        0 == strcmp(relation_attr.attribute_name.c_str(), "*")) {
      for (Table *table : tables) {
        wildcard_fields(table, query_fields, query_fields_show);
      }

    } else if (!common::is_blank(relation_attr.relation_name.c_str())) {
      const char *table_name = relation_attr.relation_name.c_str();
      const char *field_name = relation_attr.attribute_name.c_str();

      if (0 == strcmp(table_name, "*")) {
        if (0 != strcmp(field_name, "*")) {
          LOG_WARN("invalid field name while table is *. attr=%s", field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        for (Table *table : tables) {
          wildcard_fields(table, query_fields, query_fields_show);
        }
      } else {
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }

        Table *table = iter->second;
        if (0 == strcmp(field_name, "*")) {
          wildcard_fields(table, query_fields, query_fields_show);
        } else {
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }

          query_fields.push_back(Field(table, field_meta));

          std::string aggop_name;
          switch (select_sql.agg_attributes[i].agg_func)
          {
          case MAX_OP:
            aggop_name = "max";
            break;
          case MIN_OP:
            aggop_name = "min";
            break;
          case COUNT_OP:
            aggop_name = "count";
            break;
          case AVG_OP:
            aggop_name = "avg";
            break;
          case SUM_OP:
            aggop_name = "sum";
            break;
          default:
            break;
          }
          if(aggop_name == "count"){
            query_fields_show.push_back(Field(table, nullptr));
          }else{
            std::string agg_name = aggop_name + "(" + field_meta->name() + ")"; 
            const char* agg_name_char = agg_name.c_str();
            FieldMeta field_meta_show = FieldMeta(agg_name_char, field_meta->type(), field_meta->offset(), field_meta->len(), field_meta->visible());
            query_fields_show.push_back(Field(table, &field_meta_show));
          }
        }
      }
    } else {
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }

      Table *table = tables[0];
      const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name.c_str());
      if (nullptr == field_meta) {
        LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }

      query_fields.push_back(Field(table, field_meta));
      std::string aggop_name;
      switch (select_sql.agg_attributes[i].agg_func)
      {
      case MAX_OP:
        aggop_name = "max";
        break;
      case MIN_OP:
        aggop_name = "min";
        break;
      case COUNT_OP:
        aggop_name = "count";
        break;
      case AVG_OP:
        aggop_name = "avg";
        break;
      case SUM_OP:
        aggop_name = "sum";
        break;
      default:
        break;
      }
      if(aggop_name == "count"){
        query_fields_show.push_back(Field(table, nullptr));
      }else{
        std::string agg_name = aggop_name + "(" + field_meta->name() + ")"; 
        const char* agg_name_char = agg_name.c_str();
        FieldMeta field_meta_show = FieldMeta(agg_name_char, field_meta->type(), field_meta->offset(), field_meta->len(), field_meta->visible());
        query_fields_show.push_back(Field(table, &field_meta_show));
      }
    }
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_fields.size());

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db,
      default_table,
      &table_map,
      select_sql.conditions.data(),
      static_cast<int>(select_sql.conditions.size()),
      filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }
  
  // everything alright
  SelectAggStmt *select_agg_stmt = new SelectAggStmt();
  // TODO add expression copy
  select_agg_stmt->tables_.swap(tables);
  select_agg_stmt->query_fields_.swap(query_fields);
  select_agg_stmt->query_fields_show_.swap(query_fields_show);
  select_agg_stmt->filter_stmt_ = filter_stmt;
  select_agg_stmt->aggop_ = aggop;
  stmt = select_agg_stmt;
  return RC::SUCCESS;
}
