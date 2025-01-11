#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 protected:
  std::string name;
  int hitPoints;
  int energyPoints;
  int attackDamage;

  virtual void printNoEnergy(void);
  virtual void printDied(void);
  virtual void printAlreadyDead(void);

 public:
  ClapTrap();
  ClapTrap(std::string name);
  virtual ~ClapTrap();
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);

  virtual void attack(const std::string &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  virtual void printStatus(void);

  void setHitPoints(unsigned int amount);
  void setEnergyPoints(unsigned int amount);
  void setAttackDamage(unsigned int amount);
  int getAttackDamage(void) const;
  int getHitPoints(void) const;
  int getEnergyPoints(void) const;
  const std::string &getName(void) const;
};

#endif
