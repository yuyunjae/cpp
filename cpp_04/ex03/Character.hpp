#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_INVENTORY 4

class Character : public ICharacter {
 private:
  Character();
  std::string name;
  AMateria* inventory[4];

 public:
  Character(const std::string& name);
  virtual ~Character();
  Character(const Character& other);
  Character& operator=(const Character& other);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, Character& target);
};

#endif
