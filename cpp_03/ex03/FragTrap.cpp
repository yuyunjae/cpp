#include "FragTrap.hpp"

FragTrap::FragTrap() { std::cout << "FragTrap Default Constructor called\n"; }

FragTrap::FragTrap(std::string name) {
  this->name = name;
  this->hitPoints = 100;
  this->energyPoints = 100;
  this->attackDamage = 30;
  std::cout << this->name << ": FragTrap Constructor called\n";
}

FragTrap::~FragTrap() {
  std::cout << this->name << ": FragTrap Destructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << this->name << ": FragTrap Copy Constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << this->name << ": FragTrap Copy assignment operator called\n";
  if (this != &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
  }
  return *this;
}

void FragTrap::printNoEnergy(void) {
  std::cout << "FragTrap " << this->name << " has no energy!\n";
}
void FragTrap::printDied(void) {
  std::cout << "FragTrap " << this->name << " has no hitPoints!\n";
}
void FragTrap::printAlreadyDead(void) {
  std::cout << "FragTrap " << this->name << " is already dead!\n";
}
void FragTrap::printStatus(void) {
  std::cout << "FragTrap " << this->name << "'s hitPoints: " << this->hitPoints
            << ", energyPoints: " << this->energyPoints
            << ", attackDamage: " << this->attackDamage << std::endl;
}

void FragTrap::attack(const std::string &target) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    std::cout << "FragTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!\n";
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void FragTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else {
    this->hitPoints -= amount;
    if (this->hitPoints < 0) this->hitPoints = 0;
    std::cout << "FragTrap " << this->name << " takes " << amount
              << " points of damage! remaining hitPoints: " << this->hitPoints
              << std::endl;
    if (!this->hitPoints) this->printDied();
  }
}

void FragTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    this->hitPoints += amount;
    std::cout << "FragTrap " << this->name << " repairs itself. Get " << amount
              << " points! remaining hitPoints: " << this->hitPoints
              << std::endl;
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->name
            << " says: Come on, give me a high five!\n";
}
