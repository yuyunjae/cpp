#include <iostream>
#include <string>

void megaphone(std::string str) {
  for (size_t j = 0; j < str.length(); j++)
    std::cout << static_cast<char>(std::toupper(str[j]));
}

int main(int argc, char **argv) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  else {
    for (int i = 1; i < argc; i++) megaphone(argv[i]);
    std::cout << std::endl;
  }
  return (0);
}
