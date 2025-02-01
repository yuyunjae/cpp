#include "Bureaucrat.hpp"

int main(void) {
  std::cout
      << "-------------------- test1 : 정상 범위로 생성 --------------------\n";
  try {
    Bureaucrat test1("yuyu", 1);
    std::cout << test1 << std::endl;
    test1.decrement();
    std::cout << test1 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout
      << "-------------------- test2 : 비정장 범위로 생성 (1보다 높은 관료) "
         "--------------------\n";
  try {
    Bureaucrat test2("yuyu", 0);
    std::cout << test2 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout
      << "-------------------- test3 : 비정장 범위로 생성 (150보다 낮은 관료) "
         "--------------------\n";
  try {
    Bureaucrat test3("yuyu", 240);
    std::cout << test3 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test4 : 비정장 범위로 등급 이동 ( > 150) "
               "--------------------\n";
  try {
    Bureaucrat test4("yuyu", 149);
    std::cout << test4 << std::endl;
    test4.decrement();
    std::cout << test4 << std::endl;
    test4.decrement();
    std::cout << test4 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test5 : 비정장 범위로 등급 이동 ( < 1) "
               "--------------------\n";
  try {
    Bureaucrat test5("yuyu", 2);
    std::cout << test5 << std::endl;
    test5.increment();
    std::cout << test5 << std::endl;
    test5.increment();
    std::cout << test5 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test6 : copy constructor, copy assignment "
               "operator check --------------------\n";
  try {
    Bureaucrat test1("yuyu", 2);
    std::cout << test1 << std::endl;
    Bureaucrat test2(test1);
    std::cout << test2 << std::endl;
    Bureaucrat test3("chch", 130);
    std::cout << test3 << std::endl;
    test3 = test1;
    std::cout << test3 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
