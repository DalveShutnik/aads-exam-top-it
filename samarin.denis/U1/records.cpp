#include "records.hpp"

#include <cctype>
#include <cstddef>
#include <istream>
#include <string>

namespace {
  bool isSpaceChar(char symbol)
  {
    return std::isspace(static_cast< unsigned char >(symbol)) != 0;
  }

  std::string trimFront(const std::string & text)
  {
    std::size_t begin = 0;
    while (begin < text.size() && isSpaceChar(text[begin])) {
      ++begin;
    }
    return text.substr(begin);
  }

  bool containsId(const samarin::detail::list_t< samarin::Person > & records, std::size_t id)
  {
    using Node = const samarin::detail::list_node_t< samarin::Person >;
    for (Node * node = records.head; node != nullptr; node = node->next) {
      if (node->value.id == id) {
        return true;
      }
    }
    return false;
  }
}

samarin::counts_t samarin::readRecords(std::istream & input, detail::list_t< Person > & records)
{
  counts_t counts{ 0, 0 };
  while (true) {
    std::size_t id = 0;
    if (input >> id) {
      std::string rest;
      std::getline(input, rest);
      const std::string info = trimFront(rest);
      if (info.empty() || containsId(records, id)) {
        ++counts.ignored;
      } else {
        const Person person{ id, info };
        detail::pushBack(records, person);
        ++counts.accepted;
      }
    } else if (input.eof()) {
      break;
    } else {
      input.clear();
      std::string skipped;
      std::getline(input, skipped);
      ++counts.ignored;
    }
  }
  return counts;
}
