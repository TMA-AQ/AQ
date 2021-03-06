#ifndef __LINK_H__
#define __LINK_H__

#include <aq/verbs/VerbFactory.h>

namespace aq
{

struct VerbBuilder : public aq::verb::Builder_Intf
{
  aq::verb::VerbNode::Ptr build(aq::tnode::tag_t type) const;
};

}

#endif
