#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();
  virtual ~Ice();
  Ice(const Ice &other);
  Ice &operator=(const Ice &other);

  virtual Ice *clone() const;
  virtual void use(ICharacter &target);
};

#endif
