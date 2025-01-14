#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  // const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  // meta->makeSound();
  // delete meta;
  delete j;
  delete i;

  std::cout << "================ WrongAnimal, WrongCat "
               "================\n";
  const WrongAnimal* wrongAnimal = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongAnimal->getType() << std::endl;
  std::cout << wrongCat->getType() << std::endl;

  wrongAnimal->makeSound();
  wrongCat->makeSound();
  delete wrongAnimal;
  delete wrongCat;

  return 0;
}
