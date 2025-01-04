#include "Zombie.hpp"

void randomChump(std::string name) {
  // Zombie zz = Zombie(name);
  Zombie zombie(name);
  zombie.announce();
}
