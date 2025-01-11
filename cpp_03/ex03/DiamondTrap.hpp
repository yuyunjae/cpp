#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string name;  // 이거 어쩌라는 거지
  DiamondTrap();
  virtual void printNoEnergy(void);
  virtual void printDied(void);
  virtual void printAlreadyDead(void);

 public:
  DiamondTrap(std::string name);
  virtual ~DiamondTrap();
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);

  void whoAmI();

  virtual void attack(const std::string &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  virtual void printStatus(void);
};

#endif
