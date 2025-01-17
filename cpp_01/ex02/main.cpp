#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "memory address\n";
  std::cout << "str: " << &str << std::endl;
  std::cout << "stringPTR: " << stringPTR << std::endl;
  std::cout << "stringREF: " << &stringREF << std::endl;

  std::cout << "value\n";
  std::cout << "str: " << str << std::endl;
  std::cout << "stringPTR: " << *stringPTR << std::endl;
  std::cout << "stringREF: " << stringREF << std::endl;

  return 0;
}
