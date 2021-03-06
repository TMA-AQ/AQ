#include "OverVerbs.h"
#include "VerbVisitor.h"
#include <algorithm>
#include <aq/util/Exceptions.h>

using namespace std;

namespace aq {
namespace verb {

//------------------------------------------------------------------------------
bool PartitionVerb::changeQuery( aq::tnode* pStart, aq::tnode* pNode, VerbResult::Ptr resLeft, VerbResult::Ptr resRight, VerbResult::Ptr resNext )
{
  return false;
}

//------------------------------------------------------------------------------
void PartitionVerb::changeResult(  Table::Ptr table,
                                   VerbResult::Ptr resLeft, VerbResult::Ptr resRight, VerbResult::Ptr resNext )
{
  assert(false);
}

//------------------------------------------------------------------------------
void PartitionVerb::addResult( aq::Row& row )
{
}

//------------------------------------------------------------------------------
void PartitionVerb::accept(VerbVisitor* visitor)
{
  visitor->visit(this);
}

//------------------------------------------------------------------------------
void extractFrameTypeOffset(  aq::tnode* bound, TablePartition::FrameBoundType& type,
                              int& offset, bool start, int verbTag )
{
  assert( bound );
  assert( !bound->right );
  switch( bound->tag )
  {
  case K_PRECEDING:
    assert( bound->left );
    switch( bound->left->tag )
    {
    case K_UNBOUNDED:
      if( !start )
        throw verb_error( generic_error::VERB_BAD_SYNTAX, verbTag );
      type = TablePartition::AQ_UNBOUNDED; offset = 0; break;
    case K_INTEGER:
      type = TablePartition::AQ_RELATIVE;
      offset = (int) - bound->left->getData().val_int;
      break;
    default: assert(0);
    }
    break;
  case K_FOLLOWING:
    assert( bound->left );
    switch( bound->left->tag )
    {
    case K_UNBOUNDED:
      if( start )
        throw verb_error( generic_error::VERB_BAD_SYNTAX, verbTag );
      type = TablePartition::AQ_UNBOUNDED; offset = 0; break;
    case K_INTEGER:
      type = TablePartition::AQ_RELATIVE;
      offset = (int) bound->left->getData().val_int;
      break;
    default: assert(0);
    }
    break;
  case K_CURRENT: type = TablePartition::AQ_RELATIVE; offset = 0; break;
  default:
    assert( 0 );
  }
}

//------------------------------------------------------------------------------
bool FrameVerb::preprocessQuery( aq::tnode* pStart, aq::tnode* pNode, aq::tnode* pStartOriginal )
{
  assert( pNode );
  assert( pNode->left );
  TablePartition::Ptr partition = new TablePartition();
  partition->FrameUnitsInitialized = true;
  switch( pNode->left->tag )
  {
  case K_ROWS: partition->FrameUnits = TablePartition::ROWS; break;
  case K_RANGE: partition->FrameUnits = TablePartition::RANGE; break;
  default:
    assert( 0 );
  }
  assert( pNode->right );
  TablePartition::FrameBoundType type;
  int offset;
  switch( pNode->right->tag )
  {
  case K_AND:
  {
    aq::tnode* startBound = pNode->right->left;
    extractFrameTypeOffset( startBound, type, offset, true, this->getVerbType() );
    partition->FrameStartType = type;
    partition->FrameStart = offset;
    aq::tnode* endBound = pNode->right->right;
    extractFrameTypeOffset( endBound, type, offset, false, this->getVerbType() );
    partition->FrameEndType = type;
    partition->FrameEnd = offset;
  }
  break;
  case K_PRECEDING:
  {
    aq::tnode* startBound = pNode->right;
    extractFrameTypeOffset( startBound, type, offset, true, this->getVerbType() );
    partition->FrameStartType = type;
    partition->FrameStart = offset;
    partition->FrameEndType = TablePartition::AQ_RELATIVE;
  }
  break;
  default:
    assert( 0 );
  }
  this->Result = partition;
  return false;
}

//------------------------------------------------------------------------------
void FrameVerb::accept(VerbVisitor* visitor)
{
  visitor->visit(this);
}

}
}
