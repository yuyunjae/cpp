#include "whatever.hpp"

int main(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  //   const int constA = 2, constB = 3;
  //   std::cout << "min( constA, constB ) = " << ::min(constA, constB) <<
  //   std::endl; std::cout << "max( constA, constB ) = " << ::max(constA,
  //   constB) << std::endl;

  // swap error (const impossible)
  //   ::swap(constA, constB);
  //   std::cout << "constA = " << constA << ", constB = " << constB <<
  //   std::endl;

  return 0;
}
