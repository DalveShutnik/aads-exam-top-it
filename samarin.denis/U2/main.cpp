#include "model.hpp"

int main()
{
  samarin::dataset_t data{ { nullptr, nullptr }, { nullptr, nullptr } };
  samarin::detail::clear(data.persons);
  samarin::detail::clear(data.meetings);
  return 0;
}
