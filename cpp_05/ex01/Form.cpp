#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
  return ("There is no grade higher than 1. ");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade too low. ");
}

Form::Form() : name(""), sign(false), signGrade(1), execGrade(1) {
  std::cout << "Form default constructor called\n";
}

Form::Form(const std::string name, int signGrade, int execGrade)
    : name(name), sign(false), signGrade(signGrade), execGrade(execGrade) {
  std::cout << "Form default constructor called\n";
  if (this->signGrade < 1) throw Form::GradeTooHighException();
  if (this->signGrade > 150) throw Form::GradeTooLowException();
  if (this->execGrade < 1) throw Form::GradeTooHighException();
  if (this->execGrade > 150) throw Form::GradeTooLowException();
}

Form::~Form() { std::cout << "Form destructor called\n"; }

Form::Form(const Form &other)
    : name(other.name),
      sign(other.sign),
      signGrade(other.signGrade),
      execGrade(other.execGrade) {
  std::cout << "Form copy constructor called\n";
  if (this->signGrade < 1) throw Form::GradeTooHighException();
  if (this->signGrade > 150) throw Form::GradeTooLowException();
  if (this->execGrade < 1) throw Form::GradeTooHighException();
  if (this->execGrade > 150) throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
  std::cout << "Form copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->sign = other.sign;
    // this->signGrade = other.signGrade; 이거 const인데 어캐함.
    // this->execGrade = other.execGrade; 이거 const인데 어캐함.
    // 	  if (this->signGrade < 1) throw Form::GradeTooHighException();
    //   if (this->signGrade > 150) throw Form::GradeTooLowException();
    //   if (this->execGrade < 1) throw Form::GradeTooHighException();
    //   if (this->execGrade > 150) throw Form::GradeTooLowException();
  }
  return *this;
}

const std::string &Form::getName() const { return this->name; }
bool Form::getSign() const { return this->sign; }
int Form::getSignGrade() const { return this->signGrade; }
int Form::getExecGrade() const { return this->execGrade; }

void Form::beSigned(const Bureaucrat &other) {
  if (other.getGrade() > this->signGrade) throw Form::GradeTooLowException();
  this->sign = true;
}

std::ostream &operator<<(std::ostream &out, const Form &other) {
  out << other.getName()
      << ", Form sign status: " << (other.getSign() ? "True" : "False")
      << ", required sign grade: " << other.getSignGrade()
      << ", required execute grade: " << other.getExecGrade();

  return out;
}
