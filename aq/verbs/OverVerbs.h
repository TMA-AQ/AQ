#pragma once

#include "VerbNode.h"

namespace aq {
namespace verb {

//------------------------------------------------------------------------------
class PartitionVerb: public VerbNode
{
public:
  virtual int getVerbType() const { return K_PARTITION; };
  virtual bool changeQuery( aq::tnode* pStart, aq::tnode* pNode, VerbResult::Ptr resLeft, VerbResult::Ptr resRight, VerbResult::Ptr resNext );
  virtual void changeResult( Table::Ptr table, VerbResult::Ptr resLeft, VerbResult::Ptr resRight, VerbResult::Ptr resNext );
  virtual void addResult( aq::Row& row );
  virtual void accept(VerbVisitor* visitor);
};

//------------------------------------------------------------------------------
class FrameVerb: public VerbNode
{
public:
  virtual int getVerbType() const { return K_FRAME; };
  virtual bool preprocessQuery( aq::tnode* pStart, aq::tnode* pNode, aq::tnode* pStartOriginal );
  virtual void accept(VerbVisitor* visitor);
};

}
}
