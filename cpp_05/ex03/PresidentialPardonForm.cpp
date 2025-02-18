#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5) {
  std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
    : AForm(name, 25, 5) {
  std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {
  std::cout << "PresidentialPardonForm copy constructor called\n";
  if (this->getSignGrade() < 1)
    throw PresidentialPardonForm::GradeTooHighException();
  if (this->getSignGrade() > 150)
    throw PresidentialPardonForm::GradeTooLowException();
  if (this->getExecGrade() < 1)
    throw PresidentialPardonForm::GradeTooHighException();
  if (this->getExecGrade() > 150)
    throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other) {
  std::cout << "PresidentialPardonForm copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->setSign(other.getSign());
    // this->signGrade = other.signGrade; 이거 const인데 어캐함.
    // this->execGrade = other.execGrade; 이거 const인데 어캐함.
    // 	  if (this->signGrade < 1) throw
    // PresidentialPardonForm::GradeTooHighException();
    //   if (this->signGrade > 150) throw
    //   PresidentialPardonForm::GradeTooLowException(); if (this->execGrade <
    //   1) throw PresidentialPardonForm::GradeTooHighException(); if
    //   (this->execGrade > 150) throw
    //   PresidentialPardonForm::GradeTooLowException();
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign()) throw AForm::NoSignException();
  if (this->getExecGrade() < executor.getGrade())
    throw AForm::GradeTooLowException();
  std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
