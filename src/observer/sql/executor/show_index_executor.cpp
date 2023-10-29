#include "sql/executor/show_index_executor.h"
#include "sql/stmt/show_index_stmt.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "session/session.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "sql/operator/string_list_physical_operator.h"
#include "storage/index/index.h"

RC ShowIndexExecutor::execute(SQLStageEvent *sql_event)
{
    RC rc = RC::SUCCESS;
    Stmt *stmt = sql_event->stmt();
    Session *session = sql_event->session_event()->session();
    ASSERT(stmt->type() == StmtType::SHOW_INDEX, 
            "show index executor can not run this command: %d", static_cast<int>(stmt->type()));

    ShowIndexStmt *show_index_stmt = static_cast<ShowIndexStmt *>(stmt);

    Table *table = show_index_stmt->table();

    SqlResult *sql_result = sql_event->session_event()->sql_result();
    if (table != nullptr) {
        TupleSchema tuple_schema;
        tuple_schema.append_cell(TupleCellSpec("", "Table", "Table"));
        tuple_schema.append_cell(TupleCellSpec("", "Non_unique", "Non_unique"));
        tuple_schema.append_cell(TupleCellSpec("", "Key_name", "Key_name"));
        tuple_schema.append_cell(TupleCellSpec("", "Seq_in_index", "Seq_in_index"));
        tuple_schema.append_cell(TupleCellSpec("", "Column_name", "Column_name"));

        sql_result->set_tuple_schema(tuple_schema);

        auto oper = new StringListPhysicalOperator;

        std::vector<Index *> all_index = table->get_all_index();
        for (int i = 0; i < all_index.size(); i++) {
            std::vector<std::string> tmp_filed = all_index[i]->index_meta().field();
            for (int j=0; j<tmp_filed.size(); j++){
                // oper->append({table->name(), "1", all_index[i]->index_meta().name(), std::to_string(j+1), tmp_filed[j]});
                oper->append({table->name(), (all_index[i]->index_meta().unique() ? "0" : "1"), all_index[i]->index_meta().name(), std::to_string(j+1), tmp_filed[j]});
            }
        }

        sql_result->set_operator(unique_ptr<PhysicalOperator>(oper));
    } else {

        sql_result->set_return_code(RC::SCHEMA_TABLE_NOT_EXIST);
        sql_result->set_state_string("Table not exists");
    }

    return rc;
}