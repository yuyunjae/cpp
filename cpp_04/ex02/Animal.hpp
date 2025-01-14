#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

class Animal {
 protected:
  std::string type;

 public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);

  virtual void makeSound() const = 0;
  const std::string &getType(void) const;
};

#endif
