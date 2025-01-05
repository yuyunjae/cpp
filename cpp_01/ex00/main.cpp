#include "Zombie.hpp"

int main(void) {
  Zombie *zombie1 = newZombie("Foo");
  Zombie zombie2("Boo");
  Zombie zombie3("Moo");

  zombie1->announce();
  zombie2.announce();
  zombie3.announce();
  randomChump("Poo");
  delete zombie1;
  return 0;
}
