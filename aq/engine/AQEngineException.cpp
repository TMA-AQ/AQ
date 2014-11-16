#include "AQEngineException.h"

using namespace aq::engine;

AQEngineException::AQEngineException(const std::string& msg)
  : generic_error(aq::generic_error::EType::AQ_ENGINE, msg) 
{
}
