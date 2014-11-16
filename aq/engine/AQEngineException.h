#ifndef ___AQ_ENGINE_EXCEPTION_H__
#define ___AQ_ENGINE_EXCEPTION_H__

#include <aq/util/Exceptions.h>

namespace aq {
  namespace engine {

    class AQEngineException : public aq::generic_error
    {
    public:
      AQEngineException(const std::string& msg);
      virtual ~AQEngineException() throw () {}
    };

  }
}

#endif