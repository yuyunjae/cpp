#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
  int classType = rand() % 3;
  switch (classType) {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
  }
  std::cout << "generating type error\n";
  return 0;
}

void identify(Base *p) {
  std::cout << "pointer test!\n";
  if (dynamic_cast<A *>(p)) {
    std::cout << "Actual Type is A!\n";
    return;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "Actual Type is B!\n";
    return;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "Actual Type is C!\n";
    return;
  } else {
    std::cout << "Type Error occur!\n";
    return;
  }
}

void identify(Base &p) {
  std::cout << "reference test!\n";
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Actual Type is A!\n";
    return;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Actual Type is B!\n";
    return;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Actual Type is C!\n";
    return;
  } catch (std::exception &e) {
    std::cout << "Type Error occur!\n";
  }
}

int main(void) {
  std::srand(time(NULL));
  Base *randomClass = generate();
  std::cout << "--------------------- Identify class type by pointer "
               "---------------------\n";
  identify(randomClass);

  std::cout << "--------------------- Identify class type by reference "
               "---------------------\n";
  identify(*randomClass);

  std::cout << "--------------------- Error test "
               "---------------------\n";
  Base base;
  identify(&base);
  identify(base);
}
