#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
  std::cout << "DiamondTrap Default Constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), FragTrap(name), ScavTrap(name) {
  this->name = name;
  ClapTrap::name = this->name + "_clap_name";
  this->hitPoints = 100;
  this->energyPoints = 50;
  this->attackDamage = 30;
  std::cout << this->name << ": DiamondTrap Constructor called\n";
}

DiamondTrap::~DiamondTrap() {
  std::cout << this->name << ": DiamondTrap Destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other) {
  this->name = other.name;
  this->hitPoints = other.hitPoints;
  this->energyPoints = other.energyPoints;
  this->attackDamage = other.attackDamage;
  std::cout << this->name << ": DiamondTrap Copy Constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << this->name << ": DiamondTrap Copy assignment operator called\n";
  if (this != &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
  }
  return *this;
}

void DiamondTrap::printNoEnergy(void) {
  std::cout << "DiamondTrap " << this->name << " has no energy!\n";
}
void DiamondTrap::printDied(void) {
  std::cout << "DiamondTrap " << this->name << " has no hitPoints!\n";
}
void DiamondTrap::printAlreadyDead(void) {
  std::cout << "DiamondTrap " << this->name << " is already dead!\n";
}
void DiamondTrap::printStatus(void) {
  std::cout << "DiamondTrap " << this->name
            << "'s hitPoints: " << this->hitPoints
            << ", energyPoints: " << this->energyPoints
            << ", attackDamage: " << this->attackDamage << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else {
    this->hitPoints -= amount;
    if (this->hitPoints < 0) this->hitPoints = 0;
    std::cout << "DiamondTrap " << this->name << " takes " << amount
              << " points of damage! remaining hitPoints: " << this->hitPoints
              << std::endl;
    if (!this->hitPoints) this->printDied();
  }
}

void DiamondTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    this->hitPoints += amount;
    std::cout << "DiamondTrap " << this->name << " repairs itself. Get "
              << amount << " points! remaining hitPoints: " << this->hitPoints
              << std::endl;
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << this->name
            << " |||||||| ClapTrap name: " << ClapTrap::name << std::endl;
}
