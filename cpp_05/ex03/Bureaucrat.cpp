#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("There is no grade higher than 1. ");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("There is no grade lower than 150. ");
}

Bureaucrat::Bureaucrat() : name(""), grade(150) {
  std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name(name), grade(grade) {
  std::cout << "Bureaucrat default constructor called\n";
  if (this->grade < 1) throw Bureaucrat::GradeTooHighException();
  if (this->grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called\n"; }

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
  this->grade = other.grade;
  if (this->grade < 1) throw Bureaucrat::GradeTooHighException();
  if (this->grade > 150) throw Bureaucrat::GradeTooLowException();
  std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Bureaucrat copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->grade = other.grade;
    if (this->grade < 1) throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150) throw Bureaucrat::GradeTooLowException();
  }
  return *this;
}

const std::string &Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::setGrade(int grade) { this->grade = grade; }

void Bureaucrat::increment() {
  this->grade = this->grade - 1;
  if (this->grade < 1) throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement() {
  this->grade = this->grade + 1;
  if (this->grade > 150) throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {
  out << other.getName() << ", bureaucrat grade " << other.getGrade() << ". ";
  return out;
}
