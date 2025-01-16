// #include <cstdlib>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// void leaks() { system("leaks a.out"); }

int main() {
  // atexit(leaks);
  Ice ice;
  IMateriaSource* src = new MateriaSource();
  // src->learnMateria(&ice);

  // 이거 고의로 leak나게 함. &ice로 들어올 수도 있으므로..
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  delete tmp;
  tmp = src->createMateria("cure");
  me->equip(tmp);
  delete tmp;
  tmp = 0;
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;

  return 0;
}

// int main() {
//   atexit(leaks);
//   Ice ice;
//   Cure cure;
//   IMateriaSource* src = new MateriaSource();
//   src->learnMateria(&ice);
//   src->learnMateria(&cure);
//   ICharacter* me = new Character("me");
//   AMateria* tmp1;
//   AMateria* tmp2;
//   tmp1 = src->createMateria("ice");
//   me->equip(tmp1);

//   tmp2 = src->createMateria("cure");
//   me->equip(tmp2);
//   ICharacter* bob = new Character("bob");
//   me->use(0, *bob);
//   me->use(1, *bob);

//   *dynamic_cast<Character*>(bob) = *dynamic_cast<Character*>(me);
//   me->use(0, *bob);

//   delete bob;
//   delete me;
//   delete src;
//   delete tmp1;
//   delete tmp2;
//   tmp1 = 0;
//   tmp2 = 0;

//   return 0;
// }
