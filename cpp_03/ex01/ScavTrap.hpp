#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  ScavTrap();
  virtual void printNoEnergy(void);
  virtual void printDied(void);
  virtual void printAlreadyDead(void);

 public:
  ScavTrap(std::string name);
  virtual ~ScavTrap();
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);
  void guardGate();  // 이거 좀 더 생각해보기

  virtual void attack(const std::string &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  virtual void printStatus(void);
};

#endif
