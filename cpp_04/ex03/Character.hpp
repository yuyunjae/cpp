#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  typedef struct sGarbage {
    AMateria* materia;
    sGarbage* next;
  } tGarbage;
  tGarbage* garbage;
  void AddGarbage(AMateria* m);
  void cleanGarbage();
  tGarbage* cloneGarbage() const;  // copy시에 쓰레기도 복사를 해줘야하는가

  static const int maxInventory;
  std::string name;
  AMateria* inventory[4];

  Character();

 public:
  Character(const std::string& name);
  virtual ~Character();
  Character(const Character& other);
  Character& operator=(const Character& other);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};

#endif
