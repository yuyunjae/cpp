#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(const std::string name);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &other);

#endif
