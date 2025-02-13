#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137) {
  std::cout << "ShrubberyCreationForm default constructor called\n";
  // Create a file <target>_shrubbery in the working directory, and writes ASCII
  // trees inside it. => 이거 어캐 처리해야하나...
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
    : AForm(name, 73, 45) {
  std::cout << "ShrubberyCreationForm default constructor called\n";
  if (this->signGrade < 1) throw ShrubberyCreationForm::GradeTooHighException();
  if (this->signGrade > 150)
    throw ShrubberyCreationForm::GradeTooLowException();
  if (this->execGrade < 1) throw ShrubberyCreationForm::GradeTooHighException();
  if (this->execGrade > 150)
    throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : name(other.name),
      sign(other.sign),
      signGrade(other.signGrade),
      execGrade(other.execGrade) {
  std::cout << "ShrubberyCreationForm copy constructor called\n";
  if (this->signGrade < 1) throw ShrubberyCreationForm::GradeTooHighException();
  if (this->signGrade > 150)
    throw ShrubberyCreationForm::GradeTooLowException();
  if (this->execGrade < 1) throw ShrubberyCreationForm::GradeTooHighException();
  if (this->execGrade > 150)
    throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other) {
  std::cout << "ShrubberyCreationForm copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->sign = other.sign;
    // this->signGrade = other.signGrade; 이거 const인데 어캐함.
    // this->execGrade = other.execGrade; 이거 const인데 어캐함.
    // 	  if (this->signGrade < 1) throw
    // ShrubberyCreationForm::GradeTooHighException();
    //   if (this->signGrade > 150) throw
    //   ShrubberyCreationForm::GradeTooLowException(); if (this->execGrade < 1)
    //   throw ShrubberyCreationForm::GradeTooHighException(); if
    //   (this->execGrade > 150) throw
    //   ShrubberyCreationForm::GradeTooLowException();
  }
  return *this;
}
