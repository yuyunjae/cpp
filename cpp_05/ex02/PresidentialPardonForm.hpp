#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(const std::string target);
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  virtual void execute(Bureaucrat const &executor) const;
};

#endif
