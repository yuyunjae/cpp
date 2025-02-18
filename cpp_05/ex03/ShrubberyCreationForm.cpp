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
  std::fstream ofs(fileName, std::fstream::out | std::fstream::trunc);
  try {
    if (ofs.is_open()) {
      ofs << "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      "
             "&\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%' & ()\n  "
             "&_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n "
             "()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             "
             "|||\n "
             "            |||\n             |||\n       , -=-~  .-^- _\n";
    }
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
