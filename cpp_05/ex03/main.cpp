#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::cout << "-------------------- test1 : ShrubberyCreationForm 정상 실행"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    ShrubberyCreationForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test2 : ShrubberyCreationForm 비정상 실행"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    ShrubberyCreationForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
    test1.setGrade(150);  // 실행 권한보다 권한이 낮아짐.
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    ShrubberyCreationForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    // test1.signForm(formTest1); sign x 일때
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////

  std::cout << "-------------------- test3 : PresidentialPardonForm 정상 실행"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 1);
    std::cout << test1 << std::endl;
    PresidentialPardonForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test4 : PresidentialPardonForm 비정상 실행"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 1);
    std::cout << test1 << std::endl;
    PresidentialPardonForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
    test1.setGrade(150);  // 실행 권한보다 권한이 낮아짐.
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    PresidentialPardonForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    // test1.signForm(formTest1); sign x 일때
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////

  std::cout << "-------------------- test5 : RobotomyRequestForm 정상 실행"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    RobotomyRequestForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------- test6 : RobotomyRequestForm 비정상 실행"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    RobotomyRequestForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    test1.signForm(formTest1);
    test1.setGrade(150);  // 실행 권한보다 권한이 낮아짐.
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat test1("yuyu", 10);
    std::cout << test1 << std::endl;
    RobotomyRequestForm formTest1("form1");
    std::cout << formTest1 << std::endl;
    // test1.signForm(formTest1); sign x 일때
    test1.executeForm(formTest1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
