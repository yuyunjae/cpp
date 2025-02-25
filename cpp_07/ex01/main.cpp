#include "iter.hpp"

void increase(int &a) { a += 1; }
void printInt(const int &a) { std::cout << a << " "; }

void increase(double &a) { a += 2.0; }
void printDouble(const double &a) { std::cout << a << " "; }

void increase(std::string &a) { a += "!!!!!!"; }
void printString(const std::string &a) { std::cout << a << " "; }

int main(void) {
  int intTest1[5] = {0, 1, 2, 3, 4};
  const int intTest2[5] = {0, 1, 2, 3, 4};

  std::cout << "=========== int test ===========\n";
  iter(intTest1, 5, increase);
  iter(intTest1, 5, printInt);
  std::cout << std::endl;

  //   iter(intTest2, 5, increase); 불가능.
  iter(intTest2, 5, printInt);
  std::cout << std::endl << std::endl;

  std::cout << "=========== double test ===========\n";
  double doubleTest1[5] = {0.5, 1.5, 2.5, 3.5, 4.5};
  const double doubleTest2[5] = {0.5, 1.5, 2.5, 3.5, 4.5};

  iter(doubleTest1, 5, increase);
  iter(doubleTest1, 5, printDouble);
  std::cout << std::endl;

  //   iter(doubleTest2, 5, increase); 불가능.
  iter(doubleTest2, 5, printDouble);
  std::cout << std::endl;

  std::cout << "=========== string test ===========\n";
  std::string stringTest1[2] = {"hello", "world"};
  const std::string stringTest2[2] = {"hello", "world"};

  iter(stringTest1, 2, increase);
  iter(stringTest1, 2, printString);
  std::cout << std::endl;

  //   iter(stringTest2, 5, increase); 불가능.
  iter(stringTest2, 2, printString);
  std::cout << std::endl << std::endl;
}
