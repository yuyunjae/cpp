#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal Default Constructor called\n";
}

Animal::~Animal() { std::cout << "Animal Destructor called\n"; }

Animal::Animal(const Animal &other) {
  std::cout << "Animal Copy Constructor called\n";
  this->type = other.type;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal Copy assignment operator called\n";
  if (this != &other) this->type = other.type;
  return *this;
}

void Animal::makeSound() const { return; }
const std::string &Animal::getType(void) const { return this->type; }
