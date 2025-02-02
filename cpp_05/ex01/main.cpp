#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  std::cout
      << "-------------------- test1 : 정상 범위로 생성 --------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    Form formTest1("form1", 20, 15);
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout
      << "-------------------- test2 : 비정장 범위로 생성 (1보다 높은 Form) "
         "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    Form formTest1("form1", 12, 0);
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout
      << "-------------------- test3 : 비정장 범위로 생성 (150보다 낮은 Form) "
         "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    Form formTest1("form1", 15, 155);
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test4 : signGrade가 더 낮을 때 "
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 20);
    std::cout << test1 << std::endl;
    Form formTest1("form1", 15, 15);
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test5 : copy constructor, copy assignment "
               "operator check --------------------\n";
  try {
    Bureaucrat test1("yuyu", 2);
    Form formTest1("formtest1", 4, 10);
    test1.signForm(formTest1);
    std::cout << formTest1 << std::endl;
    Form formTest2(formTest1);
    std::cout << formTest2 << std::endl;
    Form formTest3("chch", 13, 123);
    std::cout << formTest3 << std::endl;
    formTest3 = formTest1;
    std::cout << formTest3 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
