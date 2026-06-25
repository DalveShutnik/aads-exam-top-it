#include <fstream>
#include <iostream>

#include "arguments.hpp"
#include "list.hpp"
#include "person.hpp"
#include "records.hpp"

int main(int argc, char ** argv)
{
  samarin::options_t options{ false, "", false, "" };
  if (!samarin::parseArguments(argc, argv, options)) {
    std::cerr << "invalid arguments\n";
    return 1;
  }

  std::ifstream inputFile;
  if (options.hasInput) {
    inputFile.open(options.inputName);
    if (!inputFile.is_open()) {
      std::cerr << "cannot open input file\n";
      return 2;
    }
  }
  std::istream & input = options.hasInput ? inputFile : std::cin;

  samarin::detail::list_t< samarin::Person > records{ nullptr, nullptr };
  const samarin::counts_t counts = samarin::readRecords(input, records);
  static_cast< void >(counts);

  samarin::detail::clear(records);
  return 0;
}
