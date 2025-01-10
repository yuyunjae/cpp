#include "ClapTrap.hpp"

int main(void) {
  const std::string name1 = "ClapTrap1";
  const std::string name2 = "ClapTrap2";
  std::cout << "------------------init-----------------\n";
  ClapTrap clapTrap1(name1);
  ClapTrap clapTrap2(name2);

  clapTrap1.printStatus();
  clapTrap2.printStatus();

  std::cout << "\n------------------ setAttackDamage -----------------\n";
  clapTrap1.setAttackDamage(4);
  clapTrap1.printStatus();

  clapTrap2.setAttackDamage(3);
  clapTrap2.printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) -----------------\n";
  clapTrap1.attack(clapTrap2.getName());
  clapTrap2.takeDamage(clapTrap1.getAttackDamage());
  clapTrap1.printStatus();
  clapTrap2.printStatus();

  std::cout << "\n------------------ Attack(2 -> 1) -----------------\n";
  clapTrap2.attack(clapTrap1.getName());
  clapTrap1.takeDamage(clapTrap2.getAttackDamage());
  clapTrap1.printStatus();
  clapTrap2.printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) * 2 -----------------\n";
  clapTrap1.attack(clapTrap2.getName());
  clapTrap2.takeDamage(clapTrap1.getAttackDamage());
  clapTrap1.attack(clapTrap2.getName());
  clapTrap2.takeDamage(clapTrap1.getAttackDamage());
  clapTrap1.printStatus();
  clapTrap2.printStatus();

  std::cout
      << "\n------------------ Attack(1 -> 2) already dead -----------------\n";
  clapTrap1.attack(clapTrap2.getName());
  clapTrap2.takeDamage(clapTrap1.getAttackDamage());
  clapTrap1.printStatus();
  clapTrap2.printStatus();
}
