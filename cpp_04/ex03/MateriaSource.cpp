#include "MateriaSource.hpp"

const int MateriaSource::maxMemory = 4;

MateriaSource::MateriaSource() {
  std::cout << "MateriaSource Default Constructor called\n";
  for (int i = 0; i < this->maxMemory; i++) this->memory[i] = 0;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource Destructor called\n";
  for (int i = 0; i < this->maxMemory; i++) {
    if (this->memory[i]) delete this->memory[i];
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  std::cout << "MateriaSource Copy Constructor called\n";
  for (int i = 0; i < this->maxMemory; i++) {
    if (other.memory[i]) {
      this->memory[i] = other.memory[i]->clone();
    }
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  AMateria* temp;
  std::cout << "MateriaSource Copy assignment operator called\n";
  if (this != &other) {
    for (int i = 0; i < this->maxMemory; i++) {
      if (other.memory[i]) {
        temp = other.memory[i]->clone();
        if (this->memory[i]) delete this->memory[i];
        this->memory[i] = temp;
      }
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
  for (int i = 0; i < this->maxMemory; i++) {
    if (!this->memory[i]) {
      this->memory[i] = materia->clone();
      //   this->memory[i] = materia;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < this->maxMemory; i++) {
    if (!type.compare(this->memory[i]->getType()))
      return (this->memory[i]->clone());
    // return this->memory[i];
  }
  return 0;
}
