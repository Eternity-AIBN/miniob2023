#include "sql/operator/project_agg_logical_operator.h"

ProjectAggLogicalOperator::ProjectAggLogicalOperator(const std::vector<Field> &fields, const std::vector<AggOp> &aggop) : fields_(fields), aggop_(aggop)
{}
