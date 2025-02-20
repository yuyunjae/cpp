#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  static const std::string str[3];
  AForm *makeRobotoForm(const std::string target);
  AForm *makePresidentialForm(const std::string target);
  AForm *makeShrubberyForm(const std::string target);

 public:
  class NoFormException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  Intern();
  virtual ~Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);

  AForm *makeForm(const std::string name, const std::string target);
};

#endif
