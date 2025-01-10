#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 private:
  ClapTrap();
  std::string name;
  int hitPoints;
  int energyPoints;
  int attackDamage;

  void printNoEnergy(void);
  void printDied(void);
  void printAlreadyDead(void);

 public:
  ClapTrap(std::string name);
  ~ClapTrap();
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void setAttackDamage(unsigned int amount);
  int getAttackDamage(void) const;
  const std::string &getName(void) const;
  void printStatus(void);
};

#endif
