#include "Intern.hpp"

const std::string Intern::str[3] = {"robotomy request", "presidential pardon",
                                    "shrubbery creation"};

Intern::Intern() { std::cout << "Intern default constructor called\n"; }

Intern::~Intern() { std::cout << "Intern destructor called\n"; }

Intern::Intern(const Intern &other) {
  std::cout << "Intern copy constructor called\n";
}

Intern Intern::operator=(const Intern &other) {
  std::cout << "Intern copy assignment operator called\n";
  return *this;
}

AForm *Intern::makeForm(const std::string name, const std::string target) {
  void (Intern::*callFunction[3])(const std::string target) = {
      &Intern::makePresidentialForm, &Intern::makeRobotoForm,
      &Intern::makeShrubberyForm};
  //   callFunction[0] = &Intern::makePresidentialForm;
  //   callFunction[1] = &Intern::makeRobotoForm;
  //   callFunction[2] = &Intern::makeShrubberyForm;

  for (int i = 0; i < 3; i++) {
    if (str[i].compare) }
}
