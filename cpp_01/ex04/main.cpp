#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "should enter three parameter!\n";
    return 1;
  }
  //   std::stringstream -> 이거 말고 fstream 써야할듯.
  return 0;
}
