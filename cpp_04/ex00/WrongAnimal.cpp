#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal Destructor called\n"; }

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy Constructor called\n";
  this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy assignment operator called\n";
  if (this != &other) this->type = other.type;
  return *this;
}

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal sound\n"; }
const std::string &WrongAnimal::getType(void) const { return this->type; }
