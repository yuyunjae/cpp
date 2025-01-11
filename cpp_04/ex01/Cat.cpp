#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat Default Constructor called\n";
  this->type = "Cat";
}

Cat::~Cat() { std::cout << "Cat Destructor called\n"; }

Cat::Cat(const Cat &other) {
  std::cout << "Cat Copy Constructor called\n";
  this->type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &other) this->type = other.type;
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow\n"; }
