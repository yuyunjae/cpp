#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource {
 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);

  virtual ~MateriaSource();
  virtual void learnMateria(AMateria*);  // 이거는 cpp에서 Amateria *ameteria로
                                         // 사용하면 될듯. 헤더파일에서 선언할
                                         // 때 이렇게 하는 방법도 있다고 함.
  virtual AMateria* createMateria(std::string const& type);
};
#endif
