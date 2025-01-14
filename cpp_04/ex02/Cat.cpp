#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat Default Constructor called\n";
  this->brain = new Brain();
  this->type = "Cat";
}

Cat::~Cat() {
  std::cout << "Cat Destructor called\n";
  delete this->brain;
}

Cat::Cat(const Cat &other) {
  std::cout << "Cat Copy Constructor called\n";
  this->brain = new Brain(*(other.brain));
  this->type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
    *this->brain = *other.brain;
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow\n"; }

const Brain &Cat::getBrain() const { return *this->brain; }
void Cat::setBrain(const Brain &brain) { *this->brain = brain; }
