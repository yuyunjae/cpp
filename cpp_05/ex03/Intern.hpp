#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  static const std::string Intern::str[3];
  void makeRobotoForm(const std::string target);
  void makePresidentialForm(const std::string target);
  void makeShrubberyForm(const std::string target);

 public:
  Intern();
  virtual ~Intern();
  Intern(const Intern &other);
  Intern operator=(const Intern &other);

  AForm *makeForm(const std::string name, const std::string target);
};

#endif
