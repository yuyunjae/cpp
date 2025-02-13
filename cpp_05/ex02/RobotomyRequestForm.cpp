#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45) {
  std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
    : AForm(name, 72, 45) {
  std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  std::cout << "RobotomyRequestForm copy constructor called\n";
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
