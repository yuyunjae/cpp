#include "ScavTrap.hpp"

int main(void) {
  const std::string name1 = "ScavTrap1";
  const std::string name2 = "ScavTrap2";
  // const std::string name3 = "ClapTrap3";

  std::cout << "------------------init-----------------\n";

  ScavTrap scavTrap1(name1);
  ScavTrap scavTrap2(name2);
  ClapTrap *clapTrap2 = &scavTrap2;
  // ClapTrap clapTrap3(name3);

  scavTrap1.setAttackDamage(40);
  scavTrap1.printStatus();
  clapTrap2->printStatus();
  // clapTrap3.printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) -----------------\n";
  scavTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(scavTrap1.getAttackDamage());
  scavTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ Attack(2 -> 1) -----------------\n";
  clapTrap2->attack(scavTrap1.getName());
  scavTrap1.takeDamage(clapTrap2->getAttackDamage());
  scavTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ Attack(1 -> 2) * 2 -----------------\n";
  scavTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(scavTrap1.getAttackDamage());
  scavTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(scavTrap1.getAttackDamage());
  scavTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout
      << "\n------------------ Attack(1 -> 2) already dead -----------------\n";
  scavTrap1.attack(clapTrap2->getName());
  clapTrap2->takeDamage(scavTrap1.getAttackDamage());
  scavTrap1.printStatus();
  clapTrap2->printStatus();

  std::cout << "\n------------------ 1, 2 gateKeeperMode -----------------\n";
  scavTrap1.guardGate();
  // clapTrap2->guardGate(); // clapTrap에서는 없는 맴버 함수이므로 주석 해제 시
  // 당연히 컴파일에러
  std::cout << "\n------------------ delete -----------------\n";
}
