#include "sql/operator/update_logical_operator.h"

UpdateLogicalOperator::UpdateLogicalOperator(Table *table, Value values, std::string attribute_name)
    : table_(table), values_(values), attribute_name_(attribute_name)
{
}
