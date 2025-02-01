#include "ScavTrap.hpp"

ScavTrap::ScavTrap() { std::cout << "ScavTrap Default Constructor called\n"; }

ScavTrap::ScavTrap(std::string name) {
  this->name = name;
  this->hitPoints = 100;
  this->energyPoints = 50;
  this->attackDamage = 20;
  std::cout << this->name << ": ScavTrap Constructor called\n";
}

ScavTrap::~ScavTrap() {
  std::cout << this->name << ": ScavTrap Destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << this->name << ": ScavTrap Copy Constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << this->name << ": ScavTrap Copy assignment operator called\n";
  if (this != &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
  }
  return *this;
}

void ScavTrap::printNoEnergy(void) {
  std::cout << "ScavTrap " << this->name << " has no energy!\n";
}
void ScavTrap::printDied(void) {
  std::cout << "ScavTrap " << this->name << " has no hitPoints!\n";
}
void ScavTrap::printAlreadyDead(void) {
  std::cout << "ScavTrap " << this->name << " is already dead!\n";
}
void ScavTrap::printStatus(void) {
  std::cout << "ScavTrap " << this->name << "'s hitPoints: " << this->hitPoints
            << ", energyPoints: " << this->energyPoints
            << ", attackDamage: " << this->attackDamage << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    std::cout << "ScavTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!\n";
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else {
    this->hitPoints -= amount;
    if (this->hitPoints < 0) this->hitPoints = 0;
    std::cout << "ScavTrap " << this->name << " takes " << amount
              << " points of damage! remaining hitPoints: " << this->hitPoints
              << std::endl;
    if (!this->hitPoints) this->printDied();
  }
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    this->hitPoints += amount;
    std::cout << "ScavTrap " << this->name << " repairs itself. Get " << amount
              << " points! remaining hitPoints: " << this->hitPoints
              << std::endl;
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!\n";
}
