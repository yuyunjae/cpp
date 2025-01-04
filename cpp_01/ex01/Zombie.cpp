#include "Zombie.hpp"

Zombie::Zombie() { this->name = ""; }

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie() {
  std::cout << "Zombie <" << this->name << "> is destroyed!\n";
}

void Zombie::announce() {
  std ::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) { this->name = name; }

Zombie *newZombie(std::string name) {
  Zombie *zombie = new Zombie(name);
  return zombie;
}

void randomChump(std::string name) {
  Zombie zombie(name);
  zombie.announce();
}
