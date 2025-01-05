#include "Zombie.hpp"

int main(void) {
  int N = 5;
  Zombie *zombies = zombieHorde(N, "Foo");

  for (int i = 0; i < N; i++) {
    zombies->announce();
  }

  // Zombie *zombie = zombies;
  // for (int i = 0; i < N; i++) {
  //   zombie->announce();
  //   zombie++;
  // }

  delete[] zombies;
  return 0;
}
