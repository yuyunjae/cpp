#include "Zombie.hpp"

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie() {
  std::cout << "Zombie <" << this->name << "> is destroyed!\n";
}

void Zombie::announce() {
  std ::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
