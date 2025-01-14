#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure Default Constructor called\n";
}

Cure::~Cure() { std::cout << "Cure Destructor called\n"; }

Cure::Cure(const Cure &other) : AMateria(other) {
  std::cout << "Cure Copy Constructor called\n";
}

Cure &Cure::operator=(const Cure &other) {
  std::cout << "Cure Copy assignment operator called\n";
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Cure *Cure::clone() const { return (new Cure()); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
