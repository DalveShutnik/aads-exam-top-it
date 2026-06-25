#ifndef SAMARIN_U2_MODEL_HPP
#define SAMARIN_U2_MODEL_HPP

#include <cstddef>
#include <string>

#include "list.hpp"

namespace samarin {
  struct person_t {
    std::size_t id;
    bool named;
    std::string description;
  };

  struct meeting_t {
    std::size_t first;
    std::size_t second;
    std::size_t duration;
  };

  struct dataset_t {
    detail::list_t< person_t > persons;
    detail::list_t< meeting_t > meetings;
  };

  bool insertPerson(dataset_t & data, std::size_t id, bool named, const std::string & description);
  person_t * findPerson(dataset_t & data, std::size_t id);
  void addMeeting(dataset_t & data, std::size_t first, std::size_t second, std::size_t duration);
  void clearDataset(dataset_t & data);
}

#endif
