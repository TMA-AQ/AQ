#pragma once

#include "verbs/VerbNode.h"

#include <aq/util/Base.h>
#include <aq/util/Table.h>

namespace aq
{

/// \deprecated
Table::Ptr solveOptimalMinMax(aq::verb::VerbNode::Ptr spTree, 
                              Base::Ptr               BaseDesc, 
                              Settings::Ptr           Settings);

}