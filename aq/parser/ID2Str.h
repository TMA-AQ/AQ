#ifndef __AQ_ID2STR_H__
#define __AQ_ID2STR_H__

#include "SQLParser.h"
#include "Parser.hpp"

namespace aq
{

//------------------------------------------------------------------------------
const char* id_to_string( unsigned int nID );

//------------------------------------------------------------------------------
const char* id_to_kstring( unsigned int nID );

//------------------------------------------------------------------------------
const char* id_to_sql_string( unsigned int nID );

}

#endif /* __AQ_ID2STR_H__ */
