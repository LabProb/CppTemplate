#include <CppTemplate/explorer.hpp>
#include <iostream>
auto main() -> int {
  char *tmp = new char('a');
  delete tmp;
  std::cout << *tmp;
  Explorer explorer;
  explorer.run();
  return 0;
}