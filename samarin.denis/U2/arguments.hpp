#ifndef SAMARIN_U2_ARGUMENTS_HPP
#define SAMARIN_U2_ARGUMENTS_HPP

#include <string>

namespace samarin {
  struct options_t {
    bool hasPersons;
    std::string personsName;
    std::string dataName;
  };

  bool parseArguments(int argc, const char * const * argv, options_t & options);
}

#endif
