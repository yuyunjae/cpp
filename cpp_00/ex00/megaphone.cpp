#include <iostream>

void megaphone(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j]; j++)
      std::cout << char(std::toupper(argv[i][j]));
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  else
    megaphone(argc, argv);
  return (0);
}
