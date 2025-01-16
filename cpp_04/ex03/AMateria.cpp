#include "AMateria.hpp"

AMateria::AMateria() { std::cout << "AMateria Default Constructor called\n"; }

AMateria::AMateria(const std::string &type) : type(type) {
  std::cout << "AMateria Constructor called\n";
}

AMateria::~AMateria() { std::cout << "AMateria Destructor called\n"; }

AMateria::AMateria(const AMateria &other) {
  std::cout << "AMateria Copy Constructor called\n";
  this->type = other.type;
}

AMateria &AMateria::operator=(const AMateria &other) {
  std::cout << "AMateria Copy assignment operator called\n";
  if (this != &other) this->type = other.type;
  return *this;
}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target) { (void)target; }
