#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog Default Constructor called\n";
  this->brain = new Brain();
  this->type = "Dog";
}

Dog::~Dog() {
  std::cout << "Dog Destructor called\n";
  delete this->brain;
}

Dog::Dog(const Dog &other) {
  std::cout << "Dog Copy Constructor called\n";
  this->brain = new Brain(*(other.brain));
  this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
    *this->brain = *other.brain;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof\n"; }

const Brain &Dog::getBrain() const { return *this->brain; }
void Dog::setBrain(const Brain &brain) { *this->brain = brain; }
