#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog Default Constructor called\n";
  this->type = "Dog";
}

Dog::~Dog() { std::cout << "Dog Destructor called\n"; }

Dog::Dog(const Dog &other) {
  std::cout << "Dog Copy Constructor called\n";
  this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Copy assignment operator called\n";
  if (this != &other) this->type = other.type;
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof\n"; }
