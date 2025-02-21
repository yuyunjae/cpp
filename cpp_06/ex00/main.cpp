#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Should enter just one parameter!\n";
    return 1;
  }
  std::string str = argv[1];
  ScalarConverter::convert(str);
  return 0;
}
