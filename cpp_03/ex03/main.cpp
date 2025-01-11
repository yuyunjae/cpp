#include "DiamondTrap.hpp"

int main(void) {
  const std::string name1 = "DiamindTrap1";
  const std::string name2 = "DiamindTrap2";
  const std::string name3 = "DiamindTrap3";
  const std::string name4 = "DiamindTrap4";
  const std::string name5 = "FragTrap1";
  const std::string name6 = "FragTrap2";

  std::cout << "------------------init-----------------\n";

  DiamondTrap diamondTrap1(name1);
  DiamondTrap diamondTrap2(name2);
  DiamondTrap diamondTrap3(name3);
  DiamondTrap diamondTrap4(name4);
  FragTrap fragTrap5(name5);
  ScavTrap scavTrap6(name6);
  ScavTrap *scavTrap1 = &diamondTrap2;
  FragTrap *fragTrap1 = &diamondTrap3;
  ClapTrap *clapTrap1 = &diamondTrap4;

  std::cout << "diamondTrap status\n";
  diamondTrap1.setAttackDamage(40);
  diamondTrap1.printStatus();
  scavTrap1->printStatus();
  fragTrap1->printStatus();
  clapTrap1->printStatus();
  std::cout << "fragTrap status\n";
  fragTrap5.printStatus();
  std::cout << "scavTrap status\n";
  scavTrap6.printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) -----------------\n";
  diamondTrap1.attack(scavTrap1->getName());
  scavTrap1->takeDamage(diamondTrap1.getAttackDamage());
  diamondTrap1.printStatus();
  scavTrap1->printStatus();

  std::cout << "\n------------------ Attack(2 -> 1) -----------------\n";
  scavTrap1->attack(diamondTrap1.getName());
  diamondTrap1.takeDamage(scavTrap1->getAttackDamage());
  diamondTrap1.printStatus();
  scavTrap1->printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) * 2 -----------------\n";
  diamondTrap1.attack(scavTrap1->getName());
  scavTrap1->takeDamage(diamondTrap1.getAttackDamage());
  diamondTrap1.attack(scavTrap1->getName());
  scavTrap1->takeDamage(diamondTrap1.getAttackDamage());
  diamondTrap1.printStatus();
  scavTrap1->printStatus();

  std::cout << "\n------------------ beRepaired 1 self -----------------\n";
  diamondTrap1.beRepaired(10);
  diamondTrap1.printStatus();

  std::cout
      << "\n------------------ Attack(1 -> 2) already dead -----------------\n";
  diamondTrap1.attack(scavTrap1->getName());
  scavTrap1->takeDamage(diamondTrap1.getAttackDamage());
  diamondTrap1.printStatus();
  scavTrap1->printStatus();

  std::cout
      << "\n------------------ diamondTrap1 guardGate, highFivesGuys, whoAmI "
         "-----------------\n";
  diamondTrap1.guardGate();
  diamondTrap1.highFivesGuys();
  diamondTrap1.whoAmI();

  std::cout
      << "\n------------------ scavTrap1 guardGate, highFivesGuys, whoAmI "
         "-----------------\n";
  scavTrap1->guardGate();
  // scavTrap1->highFivesGuys();
  // scavTrap1->whoAmI();

  std::cout
      << "\n------------------ fragTrap1 guardGate, highFivesGuys, whoAmI "
         "-----------------\n";
  // fragTrap1->guardGate();
  fragTrap1->highFivesGuys();
  // fragTrap1->whoAmI();

  std::cout
      << "\n------------------ Claptrap1 guardGate, highFivesGuys, whoAmI "
         "-----------------\n";
  // clapTrap1->guardGate();
  // clapTrap1->highFivesGuys();
  // clapTrap1->whoAmI();

  std::cout << "\n------------------ delete -----------------\n";
}
