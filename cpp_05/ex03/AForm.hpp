#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  const std::string name;
  bool sign;
  const int signGrade;
  const int execGrade;
  AForm();

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class NoSignException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class FileOpenException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  AForm(const std::string name, int signGradem, int execGrade);
  virtual ~AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);

  const std::string &getName() const;
  bool getSign() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void setSign(bool sign);

  virtual void execute(Bureaucrat const &executor) const = 0;

  void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif
