#include "model.hpp"

#include <memory>
#include <string>

bool samarin::insertPerson(dataset_t & data, std::size_t id, bool named,
    const std::string & description)
{
  detail::list_node_t< person_t > ** link = std::addressof(data.persons.head);
  while (*link != nullptr && (*link)->value.id < id) {
    link = std::addressof((*link)->next);
  }
  if (*link != nullptr && (*link)->value.id == id) {
    return false;
  }
  detail::list_node_t< person_t > * const node =
      new detail::list_node_t< person_t >{ person_t{ id, named, description }, *link };
  *link = node;
  if (node->next == nullptr) {
    data.persons.tail = node;
  }
  return true;
}

samarin::person_t * samarin::findPerson(dataset_t & data, std::size_t id)
{
  for (detail::list_node_t< person_t > * node = data.persons.head; node != nullptr; node = node->next) {
    if (node->value.id == id) {
      return std::addressof(node->value);
    }
  }
  return nullptr;
}

void samarin::addMeeting(dataset_t & data, std::size_t first, std::size_t second,
    std::size_t duration)
{
  if (first == second) {
    return;
  }
  insertPerson(data, first, false, "");
  insertPerson(data, second, false, "");
  const meeting_t meeting{ first, second, duration };
  detail::pushBack(data.meetings, meeting);
}

void samarin::clearDataset(dataset_t & data)
{
  detail::clear(data.persons);
  detail::clear(data.meetings);
}
