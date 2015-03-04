#ifndef __AQEngineBasic_H__
#define __AQEngineBasic_H__

#include <aq/engine/AQEngine_Intf.h>

namespace aq
{

class AQEngineBasic : public aq::engine::AQEngine_Intf
{
public:
  AQEngineBasic(aq::Base::Ptr _base, aq::Settings::Ptr _settings);
  void prepare() const;
  void clean() const;
  bool check() const { return true; }
  void call(const std::string& query, aq::engine::AQEngine_Intf::mode_t mode);
  void call(const aq::core::SelectStatement& stmt, aq::engine::AQEngine_Intf::mode_t mode);
  void renameResult(unsigned int id, std::vector<std::pair<std::string, std::string> >& resultTables); 
  boost::shared_ptr<aq::engine::AQMatrix> getAQMatrix();
  const std::vector<llong>& getTablesIDs() const;
private:
  aq::Base::Ptr base;
  aq::Settings::Ptr settings;
  aq::engine::AQMatrix::Ptr matrix;
  std::vector<llong> tableIDs;
};

}

#endif
