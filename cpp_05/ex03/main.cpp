// #include <stdio.h>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leak(void) { system("leaks Bureaucrat"); }

int main(void) {
  // atexit(leak);
  std::cout << "-------------------- test1 : ShrubberyCreationForm 정상 생성"
               "--------------------\n";
  AForm *rrf;
  try {
    Bureaucrat test1("yuyu", 3);
    Intern intern1;
    rrf = intern1.makeForm("shrubbery creation", "Bender1");
    std::cout << *rrf << std::endl;
    test1.signForm(*rrf);
    test1.executeForm(*rrf);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete rrf;
  rrf = 0;

  std::cout << "-------------------- test2 : PresidentialPardonForm 정상 생성"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 3);
    Intern intern1;
    rrf = intern1.makeForm("presidential pardon", "Bender2");
    std::cout << *rrf << std::endl;
    test1.signForm(*rrf);
    test1.executeForm(*rrf);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete rrf;
  rrf = 0;

  std::cout << "-------------------- test3 : RobotomyRequestForm 정상 생성"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 3);
    Intern intern1;
    rrf = intern1.makeForm("robotomy request", "Bender3");
    std::cout << *rrf << std::endl;
    test1.signForm(*rrf);
    test1.executeForm(*rrf);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete rrf;
  rrf = 0;

  std::cout << "-------------------- test4 : 존재하지않는 Form 생성 시도"
               "--------------------\n";
  try {
    Bureaucrat test1("yuyu", 3);
    Intern intern1;
    rrf = intern1.makeForm("Non-existent form", "Bender4");
    std::cout << *rrf << std::endl;
    test1.signForm(*rrf);
    test1.executeForm(*rrf);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete rrf;
  rrf = 0;
}
