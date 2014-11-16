#ifndef __AQ_ENGINE_INTF_H__
#define __AQ_ENGINE_INTF_H__

#include "AQMatrix.h"
#include <aq/Settings.h>
#include <aq/util/AQLQuery.h>

namespace aq {

/// \brief contains all aq engine api  
namespace engine {

class AQENGINE_API AQEngineCallback_Intf
{
public:
	virtual void getValue(uint64_t key, size_t packet, uint8_t*& values, size_t& size) const = 0;
};

/// \brief Interface to call aq engine and get the result
class AQENGINE_API AQEngine_Intf
{
public:
  typedef boost::shared_ptr<AQEngine_Intf> Ptr;

  enum mode_t
  {
    REGULAR, 
    NESTED_1,
    NESTED_2
  };

	virtual ~AQEngine_Intf() {}
  
  /// \brief prepare the call to aq engine (create files, directories, ...)
  virtual void prepare() const = 0;

  /// \brief clean after called aq engine (delete unused files or directories, ...)
  virtual void clean() const = 0;
  
  /// \brief call aq engine
  /// \param[in] query the string representation of the query must be an AQL Prefixed Query
  /// \param[in] mode determine if the query is a subquery of a larger query and how the result must be processed
  /// \throw an aq_engine_error exception if an error occur
  virtual void call(const std::string& query, mode_t mode = mode_t::REGULAR) = 0;

  /// \brief call aq engine
  /// \param[in] query a structure representation of the query
  /// \param[in] mode determine if the query is a subquery of a larger query and how the result must be processed
  /// \throw an aq_engine_error exception if an error occur
  virtual void call(const aq::core::SelectStatement& query, mode_t mode = mode_t::REGULAR) = 0;

  /// \brief rename result file. use for nested query creating temporary table.
  /// \param[in] id unique identifier of the query
  /// \param[out] resultTables relation between table name and temporary table
  virtual void renameResult(unsigned int id, std::vector<std::pair<std::string, std::string> >& resultTables) = 0;
	
  /// \brief get the result aq matrix
  virtual AQMatrix::Ptr getAQMatrix() = 0;
	
  /// \deprecated
  /// \brief get table id in result
  /// \return a std::vector of table id
  virtual const std::vector<llong>& getTablesIDs() const = 0;
};

AQENGINE_API AQEngine_Intf * getAQEngineSystem(const aq::Base::Ptr base, const aq::Settings::Ptr settings);
  
#if defined (WIN32)
AQENGINE_API AQEngine_Intf * getAQEngineWindow(const aq::Base::Ptr base, const aq::Settings::Ptr settings);
#endif
  
}
}

#endif
