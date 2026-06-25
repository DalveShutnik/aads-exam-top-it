#include "person_io.hpp"

#include <cstddef>
#include <istream>
#include <ostream>
#include <string>

#include "parsing.hpp"

namespace {
  using PersonNode = samarin::detail::list_node_t< samarin::Person >;
}

void samarin::readPersons(std::istream & input, Dataset & data)
{
  std::string line;
  while (std::getline(input, line)) {
    std::size_t id = 0;
    std::string description;
    if (detail::parseRecord(line, id, description)) {
      insertPerson(data, id, true, description);
    }
  }
}

void samarin::writePersons(std::ostream & output, const Dataset & data)
{
  for (const PersonNode * node = data.persons.head; node != nullptr; node = node->next) {
    if (node->value.named) {
      output << node->value.id << ' ' << node->value.description << '\n';
    }
  }
}
