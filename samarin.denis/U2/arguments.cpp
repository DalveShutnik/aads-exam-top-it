#include "arguments.hpp"

#include <string>

namespace {
  bool hasPrefix(const std::string & text, const std::string & prefix)
  {
    return text.size() >= prefix.size() && text.compare(0, prefix.size(), prefix) == 0;
  }
}

bool samarin::parseArguments(int argc, const char * const * argv, options_t & options)
{
  const std::string personsPrefix = "in:";
  const std::string dataPrefix = "data:";
  const int minArguments = 1;
  const int maxArguments = 2;
  const int count = argc - 1;
  if (count < minArguments || count > maxArguments) {
    return false;
  }
  bool hasData = false;
  for (int i = 1; i < argc; ++i) {
    const std::string argument = argv[i];
    if (hasPrefix(argument, personsPrefix)) {
      const std::string name = argument.substr(personsPrefix.size());
      if (options.hasPersons || name.empty()) {
        return false;
      }
      options.hasPersons = true;
      options.personsName = name;
    } else if (hasPrefix(argument, dataPrefix)) {
      const std::string name = argument.substr(dataPrefix.size());
      if (hasData || name.empty()) {
        return false;
      }
      hasData = true;
      options.dataName = name;
    } else {
      return false;
    }
  }
  return hasData;
}
