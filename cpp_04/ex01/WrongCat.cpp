#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "WrongCat Default Constructor called\n";
  this->type = "WrongCat";
}

WrongCat::~WrongCat() { std::cout << "WrongCat Destructor called\n"; }

WrongCat::WrongCat(const WrongCat &other) {
  std::cout << "WrongCat Copy Constructor called\n";
  this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat Copy assignment operator called\n";
  if (this != &other) this->type = other.type;
  return *this;
}

void WrongCat::makeSound() const { std::cout << "Meow\n"; }
