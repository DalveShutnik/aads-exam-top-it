#include <iostream>

#include "arguments.hpp"

int main(int argc, char ** argv)
{
  samarin::options_t options{ false, "", false, "" };
  if (!samarin::parseArguments(argc, argv, options)) {
    std::cerr << "invalid arguments\n";
    return 1;
  }
  return 0;
}
