#ifndef SAMARIN_COMMON_PERSON_HPP
#define SAMARIN_COMMON_PERSON_HPP

#include <cstddef>
#include <string>

namespace samarin {
  struct Person {
    std::size_t id;
    bool named;
    std::string description;
  };
}

#endif
