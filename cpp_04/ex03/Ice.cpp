#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice Default Constructor called\n";
}

Ice::~Ice() { std::cout << "Ice Destructor called\n"; }

Ice::Ice(const Ice &other) : AMateria(other) {
  std::cout << "Ice Copy Constructor called\n";
}

Ice &Ice::operator=(const Ice &other) {
  std::cout << "Ice Copy assignment operator called\n";
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Ice *Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
