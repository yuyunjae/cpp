// #include <iostream>

// #include "Fixed.hpp"
// int main(void) {
//   Fixed a;
//   Fixed const b(Fixed(5.05f) * Fixed(2));
//   std::cout << a << std::endl;
//   std::cout << ++a << std::endl;
//   std::cout << a << std::endl;
//   std::cout << a++ << std::endl;
//   std::cout << a << std::endl;
//   std::cout << b << std::endl;
//   std::cout << Fixed::max(a, b) << std::endl;
//   return 0;
// }

#include <typeinfo>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed c(Fixed(5.2f) / Fixed(2));
  Fixed check1(2.2f);
  Fixed check2(5.5f);
  Fixed d(c / a);
  std::cout << d << std::endl;
  std::cout << check1 / check2 << std::endl;
  std::cout << typeid(c / a).name() << std::endl;
  std::cout << c << std::endl;
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << ++c << std::endl;
  std::cout << b + c << std::endl;
  std::cout << b - c << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << Fixed::min(a, b) << std::endl;
  return 0;
}
