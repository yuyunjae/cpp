#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 private:
  FragTrap();
  virtual void printNoEnergy(void);
  virtual void printDied(void);
  virtual void printAlreadyDead(void);

 public:
  FragTrap(std::string name);
  virtual ~FragTrap();
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
  void highFivesGuys();  // 이거 좀 더 생각해보기

  virtual void attack(const std::string &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  virtual void printStatus(void);
};

#endif
