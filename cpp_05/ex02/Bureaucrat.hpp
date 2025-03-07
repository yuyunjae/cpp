#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
 private:
  const std::string name;
  int grade;  // [1, 150]
  Bureaucrat();

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  Bureaucrat(const std::string name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  const std::string &getName() const;
  int getGrade() const;

  void setGrade(int grade);

  void increment();
  void decrement();
  void signForm(AForm &form);
  void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
