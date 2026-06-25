#ifndef SAMARIN_COMMON_PERSON_IO_HPP
#define SAMARIN_COMMON_PERSON_IO_HPP

#include <iosfwd>

#include "model.hpp"

namespace samarin {
  void readPersons(std::istream & input, Dataset & data);
  void writePersons(std::ostream & output, const Dataset & data);
}

#endif
