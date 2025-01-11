#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << this->name << ": ClapTrap Constructor called\n";
}

ClapTrap::~ClapTrap() {
  std::cout << this->name << ": ClapTrap Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage) {
  std::cout << this->name << ": ClapTrap Copy Constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << this->name << ": ClapTrap Copy assignment operator called\n";
  if (this != &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
  }
  return *this;
}

void ClapTrap::printNoEnergy(void) {
  std::cout << "ClapTrap " << this->name << " has no energy!\n";
}
void ClapTrap::printDied(void) {
  std::cout << "ClapTrap " << this->name << " has no hitPoints!\n";
}
void ClapTrap::printAlreadyDead(void) {
  std::cout << "ClapTrap " << this->name << " is already dead!\n";
}
void ClapTrap::printStatus(void) {
  std::cout << "ClapTrap " << this->name << "'s hitPoints: " << this->hitPoints
            << ", energyPoints: " << this->energyPoints
            << ", attackDamage: " << this->attackDamage << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    std::cout << "ClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!\n";
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else {
    this->hitPoints -= amount;
    if (this->hitPoints < 0) this->hitPoints = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount
              << " points of damage! remaining hitPoints: " << this->hitPoints
              << std::endl;
    if (!this->hitPoints) this->printDied();
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints <= 0)
    this->printAlreadyDead();
  else if (this->energyPoints > 0) {
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " repairs itself. Get " << amount
              << " points! remaining hitPoints: " << this->hitPoints
              << std::endl;
    this->energyPoints--;
  } else
    this->printNoEnergy();
}

void ClapTrap::setAttackDamage(unsigned int amount) {
  this->attackDamage = amount;
  std::cout << "ClapTrap " << this->name << " set " << amount
            << " attackDamage.\n";
}
void ClapTrap::setHitPoints(unsigned int amount) { this->hitPoints = amount; }
void ClapTrap::setEnergyPoints(unsigned int amount) {
  this->energyPoints = amount;
}

int ClapTrap::getAttackDamage(void) const { return this->attackDamage; }
int ClapTrap::getHitPoints(void) const { return this->hitPoints; }
int ClapTrap::getEnergyPoints(void) const { return this->energyPoints; }
const std::string &ClapTrap::getName(void) const { return this->name; }
