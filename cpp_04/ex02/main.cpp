#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void checkLeak() { system("leaks animal"); }

int main() {
  atexit(checkLeak);
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
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

  std::cout << "================ Array test ================\n";

  Animal* arr[10];
  for (int i = 0; i < 5; i++) {
    arr[i] = new Dog();
  }
  for (int i = 5; i < 10; i++) {
    arr[i] = new Cat();
  }
  delete arr[0];
  arr[0] = new Dog();
  for (int i = 0; i < 10; i++) delete arr[i];

  std::cout << "================ Brain test ================\n";

  std::string idea1 = "idea1";
  std::string idea2 = "idea2";
  Dog dog1;
  Brain* brain1 = new Brain();
  Brain* brain2 = new Brain();
  Brain* brain3(new Brain());
  delete brain3;
  brain1->setIdea(1, idea1);
  // std::cout << "idea index1 size: " << brain1->getIdea(1).size()
  //           << ", value: " << brain1->getIdea(1) << std::endl;
  brain2->setIdea(1, idea1);
  std::cout << "idea index1 size: " << brain2->getIdea(1).size()
            << ", value: " << brain2->getIdea(1) << std::endl;
  brain2->setIdea(1, idea2);
  std::cout << "idea index1 size: " << brain2->getIdea(1).size()
            << ", value: " << brain2->getIdea(1) << std::endl;

  std::cout << "================ Dog1 test ================\n";
  dog1.setBrain(Brain());
  std::cout << "idea index1 size: " << dog1.getBrain().getIdea(1).size()
            << ", value: " << dog1.getBrain().getIdea(1) << std::endl;
  dog1.setBrain(*brain1);
  std::cout << "idea index1 size: " << dog1.getBrain().getIdea(1).size()
            << ", value: " << dog1.getBrain().getIdea(1) << std::endl;
  dog1.setBrain(*brain2);
  std::cout << "idea index1 size: " << dog1.getBrain().getIdea(1).size()
            << ", value: " << dog1.getBrain().getIdea(1) << std::endl;

  std::cout
      << "================ Copy operator: Dog1 to Dog2 test ================\n";
  Dog dog2;
  dog2 = dog1;
  std::cout << "idea index1 size: " << dog2.getBrain().getIdea(1).size()
            << ", value: " << dog2.getBrain().getIdea(1) << std::endl;
  std::cout << "================ Copy Constructor: Dog2 to Dog3 test "
               "================\n";
  Dog dog3(dog2);
  std::cout << "idea index1 size: " << dog3.getBrain().getIdea(1).size()
            << ", value: " << dog3.getBrain().getIdea(1) << std::endl;
  std::cout << "================ delete ================\n";
  delete brain1;
  delete brain2;
  return 0;
}
