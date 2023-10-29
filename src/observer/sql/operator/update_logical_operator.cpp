#include "sql/operator/update_logical_operator.h"

// UpdateLogicalOperator::UpdateLogicalOperator(Table *table, std::vector<Value> values, std::vector<std::string> attribute_name)
//     : table_(table)
// {
//     // values_(values), attribute_name_(attribute_name)
//     for(int i=0; i<attribute_name.size(); i++){
//         std::string *tmp_string = new std::string(attribute_name[i].c_str());
//         attribute_name_.push_back(*tmp_string);

//         Value *tmp_value = new Value(values[i].attr_type(), values[i].get_data(), values[i].length());
//         values_.push_back(*tmp_value);
//     }
// }
UpdateLogicalOperator::UpdateLogicalOperator(Table *table, std::vector<Expression *> &exprs, std::vector<const FieldMeta *> &fields, std::vector<std::string> &attribute_name)
    : table_(table), exprs_(exprs), fields_(fields), attribute_name_(attribute_name)
{
}