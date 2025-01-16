#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
 protected:
  AMateria();
  std::string type;

 public:
  AMateria(const std::string &type);
  virtual ~AMateria();
  AMateria(const AMateria &other);
  AMateria &operator=(const AMateria &other);

  std::string const &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
