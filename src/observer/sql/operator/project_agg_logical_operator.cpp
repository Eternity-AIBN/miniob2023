#include "sql/operator/project_agg_logical_operator.h"

ProjectAggLogicalOperator::ProjectAggLogicalOperator(const std::vector<Field> &fields, const std::vector<AggOp> &aggop, const std::vector<bool> &select_count_star) : fields_(fields), aggop_(aggop), select_count_star_(select_count_star)
{}
