#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(0) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void HumanB::attack() {
  if (this->weapon) {
    std::cout << this->name << " attacks with their " << this->weapon->getType()
              << std::endl;
  } else
    std::cout << this->name << " has no weapon!\n";
}
