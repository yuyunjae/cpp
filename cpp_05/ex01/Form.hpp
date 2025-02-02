#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string name;
  bool sign;
  const int signGrade;
  const int execGrade;
  Form();

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  Form(const std::string name, int signGradem, int execGrade);
  ~Form();
  Form(const Form &other);
  Form &operator=(const Form &other);

  const std::string &getName() const;
  bool getSign() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif
