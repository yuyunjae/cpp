#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45) {
  std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm default constructor called\n";
  this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  std::cout << "RobotomyRequestForm copy constructor called\n";
  this->_target = other._target;
  if (this->getSignGrade() < 1)
    throw RobotomyRequestForm::GradeTooHighException();
  if (this->getSignGrade() > 150)
    throw RobotomyRequestForm::GradeTooLowException();
  if (this->getExecGrade() < 1)
    throw RobotomyRequestForm::GradeTooHighException();
  if (this->getExecGrade() > 150)
    throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
  std::cout << "RobotomyRequestForm copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->setSign(other.getSign());
    this->_target = other._target;
    // this->signGrade = other.signGrade; 이거 const인데 어캐함.
    // this->execGrade = other.execGrade; 이거 const인데 어캐함.
    // 	  if (this->signGrade < 1) throw
    // RobotomyRequestForm::GradeTooHighException();
    //   if (this->signGrade > 150) throw
    //   RobotomyRequestForm::GradeTooLowException(); if (this->execGrade < 1)
    //   throw RobotomyRequestForm::GradeTooHighException(); if
    //   (this->execGrade > 150) throw
    //   RobotomyRequestForm::GradeTooLowException();
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign()) throw AForm::NoSignException();
  if (this->getExecGrade() < executor.getGrade())
    throw AForm::GradeTooLowException();

  std::cout << "weeeeeeeeeeeeeeeeeeeeing!!\n";
  std::srand(std::time(NULL));
  if (std::rand() % 2)
    std::cout << this->_target << " has been robotomized successfully.\n";
  else
    std::cout << this->_target << " robotomy failed.\n";
}
