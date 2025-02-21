#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;
  ShrubberyCreationForm();
  void shrubberyCreation() const;

 public:
  ShrubberyCreationForm(const std::string target);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  virtual void execute(Bureaucrat const &executor) const;
};

#endif
