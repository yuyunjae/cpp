#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
  return ("There is no grade higher than 1. ");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade too low. ");
}

const char *AForm::NoSignException::what() const throw() {
  return ("The Form must be signed before running. ");
}

const char *AForm::FileOpenException::what() const throw() {
  return ("File open error! ");
}

AForm::AForm() : name(""), sign(false), signGrade(1), execGrade(1) {
  std::cout << "AForm default constructor called\n";
}

AForm::AForm(const std::string name, int signGrade, int execGrade)
    : name(name), sign(false), signGrade(signGrade), execGrade(execGrade) {
  std::cout << "AForm default constructor called\n";
  if (this->signGrade < 1) throw AForm::GradeTooHighException();
  if (this->signGrade > 150) throw AForm::GradeTooLowException();
  if (this->execGrade < 1) throw AForm::GradeTooHighException();
  if (this->execGrade > 150) throw AForm::GradeTooLowException();
}

AForm::~AForm() { std::cout << "AForm destructor called\n"; }

AForm::AForm(const AForm &other)
    : name(other.name),
      sign(other.sign),
      signGrade(other.signGrade),
      execGrade(other.execGrade) {
  std::cout << "AForm copy constructor called\n";
  if (this->signGrade < 1) throw AForm::GradeTooHighException();
  if (this->signGrade > 150) throw AForm::GradeTooLowException();
  if (this->execGrade < 1) throw AForm::GradeTooHighException();
  if (this->execGrade > 150) throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other) {
  std::cout << "AForm copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->sign = other.sign;
    // this->signGrade = other.signGrade; 이거 const인데 어캐함.
    // this->execGrade = other.execGrade; 이거 const인데 어캐함.
    // 	  if (this->signGrade < 1) throw AForm::GradeTooHighException();
    //   if (this->signGrade > 150) throw AForm::GradeTooLowException();
    //   if (this->execGrade < 1) throw AForm::GradeTooHighException();
    //   if (this->execGrade > 150) throw AForm::GradeTooLowException();
  }
  return *this;
}

const std::string &AForm::getName() const { return this->name; }
bool AForm::getSign() const { return this->sign; }
int AForm::getSignGrade() const { return this->signGrade; }
int AForm::getExecGrade() const { return this->execGrade; }

void AForm::setSign(bool sign) { this->sign = sign; }

void AForm::beSigned(const Bureaucrat &other) {
  if (other.getGrade() > this->signGrade) throw AForm::GradeTooLowException();
  this->sign = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &other) {
  out << other.getName()
      << ", AForm sign status: " << (other.getSign() ? "True" : "False")
      << ", required sign grade: " << other.getSignGrade()
      << ", required execute grade: " << other.getExecGrade();

  return out;
}
