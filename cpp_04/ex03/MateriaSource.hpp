#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
 private:
  static const int maxMemory;
  AMateria* memory[4];

 public:
  MateriaSource();
  virtual ~MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);

  virtual void learnMateria(AMateria*);
  virtual AMateria* createMateria(std::string const& type);
};

#endif
