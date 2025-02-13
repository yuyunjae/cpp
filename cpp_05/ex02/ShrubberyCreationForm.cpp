#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137) {
  std::cout << "ShrubberyCreationForm default constructor called\n";
  // Create a file <target>_shrubbery in the working directory, and writes ASCII
  // trees inside it. => 이거 어캐 처리해야하나...
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
    : AForm(name, 145, 137) {
  std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
  std::cout << "ShrubberyCreationForm copy constructor called\n";
  if (this->getSignGrade() < 1)
    throw ShrubberyCreationForm::GradeTooHighException();
  if (this->getSignGrade() > 150)
    throw ShrubberyCreationForm::GradeTooLowException();
  if (this->getExecGrade() < 1)
    throw ShrubberyCreationForm::GradeTooHighException();
  if (this->getExecGrade() > 150)
    throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other) {
  std::cout << "ShrubberyCreationForm copy asignment operator called\n";
  if (this != &other) {
    // this->name = other.name;  이거 const인데 어캐함.
    this->setSign(other.getSign());
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

void ShrubberyCreationForm::shrubberyCreation() const {
  std::string fileName = this->getName() + "_shrubbery";
  std::fstream ofs;
  ofs.exceptions(std::fstream::failbit | std::fstream::badbit);
  try {
    ofs.open(fileName, std::fstream::out | std::fstream::trunc);
    ofs << "make tree!"
        << std::endl;  // 이거 tree구현하는 함수 따로 만들어야 할듯?

    ofs.close();
  } catch (std::exception &e) {
    throw e;
  }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign()) throw AForm::NoSignException();

  if (this->getExecGrade() < executor.getGrade())
    throw AForm::GradeTooLowException();
  shrubberyCreation();
}
