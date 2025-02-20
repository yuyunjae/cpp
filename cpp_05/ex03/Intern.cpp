#include "Intern.hpp"

const std::string Intern::str[3] = {"robotomy request", "presidential pardon",
                                    "shrubbery creation"};

const char *Intern::NoFormException::what() const throw() {
  return ("The corresponding form could not be found. ");
}

Intern::Intern() { std::cout << "Intern default constructor called\n"; }

Intern::~Intern() { std::cout << "Intern destructor called\n"; }

Intern::Intern(const Intern &other) {
  std::cout << "Intern copy constructor called\n";
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "Intern copy assignment operator called\n";
  return *this;
}

AForm *Intern::makeRobotoForm(const std::string target) {
  std::cout << "Intern creates RobotomyRequestForm.\n";
  return (new RobotomyRequestForm(target));
}
AForm *Intern::makePresidentialForm(const std::string target) {
  std::cout << "Intern creates PresidentialPardonForm.\n";
  return (new PresidentialPardonForm(target));
}
AForm *Intern::makeShrubberyForm(const std::string target) {
  std::cout << "Intern creates ShrubberyCreationForm.\n";
  return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string name, const std::string target) {
  AForm *(Intern::*callFunction[3])(const std::string target) = {
      &Intern::makeRobotoForm, &Intern::makePresidentialForm,
      &Intern::makeShrubberyForm};

  for (int i = 0; i < 3; i++) {
    if (!str[i].compare(name)) {
      AForm *form = (this->*callFunction[i])(target);
      return form;
    };
  }
  throw NoFormException();
}
