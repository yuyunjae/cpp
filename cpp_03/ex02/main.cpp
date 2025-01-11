#include "FragTrap.hpp"
// #include "ScavTrap.hpp"

int main(void) {
  const std::string name1 = "FragTrap1";
  const std::string name2 = "FragTrap2";

  std::cout << "------------------init-----------------\n";

  FragTrap fragTrap1(name1);
  FragTrap fragTrap2(name2);
  ClapTrap *clapTrap2 = &fragTrap2;

  fragTrap1.setAttackDamage(40);
  fragTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) -----------------\n";
  fragTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(fragTrap1.getAttackDamage());
  fragTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ Attack(2 -> 1) -----------------\n";
  clapTrap2->attack(fragTrap1.getName());
  fragTrap1.takeDamage(clapTrap2->getAttackDamage());
  fragTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) * 2 -----------------\n";
  fragTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(fragTrap1.getAttackDamage());
  fragTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(fragTrap1.getAttackDamage());
  fragTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout
      << "\n------------------ Attack(1 -> 2) already dead -----------------\n";
  fragTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(fragTrap1.getAttackDamage());
  fragTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ 1, 2 highFivesGuys -----------------\n";
  fragTrap1.highFivesGuys();
  // clapTrap2->highFivesGuys();  // clapTrap에서는 없는 맴버 함수이므로 주석
  // 해제 시 당연히 컴파일에러
  std::cout << "\n------------------ delete -----------------\n";
}
