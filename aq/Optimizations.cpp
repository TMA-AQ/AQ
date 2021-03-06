#include "Optimizations.h"
#include "verbs/AuxiliaryVerbs.h"
#include <aq/util/Exceptions.h>
#include <aq/util/Database.h>
#include <aq/util/FileCloser.h>
#include <boost/scoped_array.hpp>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

namespace aq
{

//-------------------------------------------------------------------------------
template <typename T>
typename ColumnItem<T>::Ptr getMinMaxFromThesaurus(Column::Ptr column, size_t tableID, size_t colIdx, size_t partIdx, bool min, Base::Ptr baseDesc, Settings::Ptr settings)
{
  typename ColumnItem<T>::Ptr minMax = nullptr;
  size_t tableIdx = 0;
  for (tableIdx = 0; tableIdx < baseDesc->getTables().size(); ++tableIdx)
  {
    if (baseDesc->getTables()[tableIdx]->ID == tableID)
      break;
  }
  auto fileName = fs::path(settings->dataPath) / Database::getThesaurusFileName(tableIdx + 1, colIdx + 1, partIdx);
  FILE* pFIn = fopen(fileName.c_str(), "rb");
  if ( pFIn == nullptr )
    return minMax;
  FileCloser fileCloser(pFIn);

  size_t binItemSize  = 0;
  size_t tmpBufSize = 1000;
  switch( column->getType() )
  {
  case COL_TYPE_INT:
    binItemSize = 4;
    break;
  case COL_TYPE_BIG_INT:
  case COL_TYPE_DATE:
  case COL_TYPE_DOUBLE:
    binItemSize = 8;
    break;
  case COL_TYPE_VARCHAR:
    binItemSize = column->getSize();
    tmpBufSize = column->getSize() + 1000;
    break;
  default:
    throw generic_error(generic_error::NOT_IMPLEMENTED, "type not supported");
  }

  unsigned char *pTmpBuf = new unsigned char[tmpBufSize];
  boost::scoped_array<unsigned char> pTmpBufDel( pTmpBuf );
  if( !min )
  {
    //get the file size
    if( fseek( pFIn, 0, SEEK_END ) != 0 )
      assert( 0 );
    long fileSize = ftell( pFIn );
    if( fileSize == -1 )
      assert( 0 );
    if( fseek( pFIn, fileSize - static_cast<long>(binItemSize), SEEK_SET ) != 0 )
      assert( 0 );
  }
  if( fread( pTmpBuf, 1, binItemSize, pFIn ) != binItemSize )
    throw generic_error(generic_error::INVALID_FILE, "invalid thesaurus file [%s]", fileName.c_str());

  switch( column->getType() )
  {
  case COL_TYPE_INT:
  {
    int *pItemData = (int*)( pTmpBuf );
    minMax = new ColumnItem<int32_t>( *pItemData );
  }
  break;
  case COL_TYPE_BIG_INT:
  case COL_TYPE_DATE:
  {
    int64_t *pItemData = (int64_t*)( pTmpBuf );
    minMax = new ColumnItem<int64_t>(*pItemData );
  }
  break;
  case COL_TYPE_DOUBLE:
  {
    double *pItemData = (double*)( pTmpBuf );
    minMax = new ColumnItem<double>( *pItemData );
  }
  break;
  case COL_TYPE_VARCHAR:
    pTmpBuf[column->getSize()] = '\0';
    minMax = new ColumnItem<char*>( (char*) pTmpBuf );
    break;
  }

  return minMax;
}

//-------------------------------------------------------------------------------
Table::Ptr solveOptimalMinMax(aq::verb::VerbNode::Ptr spTree,
                              Base::Ptr baseDesc,
                              Settings::Ptr settings )
{
  if( !spTree->getLeftChild() )
  {
    return Table::Ptr();
    // throw generic_error(generic_error::INVALID_QUERY, "");
  }
  aq::verb::VerbNode::Ptr verb1 = spTree->getLeftChild();
  aq::verb::VerbNode::Ptr verb2 = nullptr;
  if( !verb1 )
    return Table::Ptr();;
  if ((verb1->getVerbType() == K_MIN) || (verb1->getVerbType() == K_MAX))
    verb2 = verb1->getLeftChild();
  else if ((verb1->getVerbType() == K_AS) && ((verb1->getLeftChild()->getVerbType() == K_MIN) || (verb1->getLeftChild()->getVerbType() == K_MAX)))
    verb2 = verb1->getLeftChild()->getLeftChild();
  else
    return Table::Ptr();;

  if( verb2->getVerbType() != K_PERIOD )
    return Table::Ptr();;
  if( spTree->getBrother() == nullptr )
    return Table::Ptr();;
  aq::verb::VerbNode::Ptr spNode = spTree;
  do
  {
    if( spNode->getVerbType() == K_WHERE )
      return Table::Ptr();;
    spNode = spNode->getBrother();
  } while( spNode->getBrother() );

  aq::verb::ColumnVerb::Ptr columnVerb = boost::dynamic_pointer_cast<aq::verb::ColumnVerb>( verb2 );
  Table::Ptr table = baseDesc->getTable( columnVerb->getTableName() );
  size_t colIdx = table->getColumnIdx( columnVerb->getColumnOnlyName() );
  Column::Ptr column = table->Columns[colIdx];

  // ColumnItem::Ptr minMax = nullptr;
  // bool min = verb1->getVerbType() == K_MIN;
  for( int partIdx = 0; ; ++partIdx )
  {
    //ColumnItem::Ptr item = getMinMaxFromThesaurus( table->ID, colIdx, partIdx, min, baseDesc, settings );
    //if( !item )
    //  break;
    //if( !minMax )
    //  minMax = item;
    //else
    //  if( min == ColumnItem::lessThan(item.get(), minMax.get(), column->Type) )
    //    minMax = item;
  }

  assert(false);
  table.reset(new Table("", 0, 1));
  Column::Ptr newColumn(new Column(*column));
  table->Columns.push_back(newColumn);
  return table;
}

}
