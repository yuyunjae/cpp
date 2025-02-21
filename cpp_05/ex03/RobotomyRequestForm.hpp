#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;
  RobotomyRequestForm();

 public:
  RobotomyRequestForm(const std::string target);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  virtual void execute(Bureaucrat const &executor) const;
};

#endif
