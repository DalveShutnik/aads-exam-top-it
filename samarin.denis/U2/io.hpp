#ifndef SAMARIN_U2_IO_HPP
#define SAMARIN_U2_IO_HPP

#include <iosfwd>

#include "model.hpp"

namespace samarin {
  bool readMeetings(std::istream & input, Dataset & data);
}

#endif
