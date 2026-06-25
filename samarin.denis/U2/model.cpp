#include "model.hpp"

#include <memory>
#include <string>

namespace {
  using PersonNode = samarin::detail::list_node_t< samarin::Person >;
}

bool samarin::insertPerson(Dataset & data, std::size_t id, bool named,
    const std::string & description)
{
  PersonNode ** link = std::addressof(data.persons.head);
  while (*link != nullptr && (*link)->value.id < id) {
    link = std::addressof((*link)->next);
  }
  if (*link != nullptr && (*link)->value.id == id) {
    return false;
  }
  PersonNode * const node = new PersonNode{ Person{ id, named, description }, *link };
  *link = node;
  if (node->next == nullptr) {
    data.persons.tail = node;
  }
  return true;
}

samarin::Person * samarin::findPerson(Dataset & data, std::size_t id)
{
  for (PersonNode * node = data.persons.head; node != nullptr; node = node->next) {
    if (node->value.id == id) {
      return std::addressof(node->value);
    }
  }
  return nullptr;
}

void samarin::addMeeting(Dataset & data, std::size_t first, std::size_t second,
    std::size_t duration)
{
  if (first == second) {
    return;
  }
  insertPerson(data, first, false, "");
  insertPerson(data, second, false, "");
  const Meeting meeting{ first, second, duration };
  detail::pushBack(data.meetings, meeting);
}

void samarin::clearDataset(Dataset & data)
{
  detail::clear(data.persons);
  detail::clear(data.meetings);
}
