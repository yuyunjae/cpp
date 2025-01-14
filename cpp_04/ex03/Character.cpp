#include "Character.hpp"

Character::Character() {
  std::cout << "Character Default Constructor called\n";
  for (int i = 0; i < MAX_INVENTORY; i++) inventory[i] = 0;
}

Character::Character(const std::string& name) : name(name) {
  std::cout << "Character Constructor called\n";
  for (int i = 0; i < MAX_INVENTORY; i++) inventory[i] = 0;
}

Character::~Character() {
  std::cout << "Character  Destructor called\n";
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (this->inventory[i]) {
      delete this->inventory[i];
    }
  }
}

Character::Character(const Character& other) {
  AMateria* temp;
  std::cout << "Character Copy Constructor called\n";
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (other.inventory[i]) {
      temp = other.inventory[i]->clone();
      delete other.inventory[i];
      other.inventory[i] = 0;  // 이거 const인데 어캐 주냐...
      this->inventory[i] = temp;
    }
  }
}

// 이거 위의 대입 생성자처럼 inventory되게 바꿔야함.
// Character& Character::operator=(const Character& other) {
//   std::cout << "Character Copy assignment operator called\n";
//   if (this != &other) {
//     for (int i = 0; i < MAX_INVENTORY; i++)
//       this->inventory[i] = other.inventory[i];
//   }
//   return *this;
// }

std::string const& Character::getName() const { return this->name; }

void Character::equip(AMateria* m) {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (!this->inventory[i]) {
      this->inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (this->inventory[idx]) this->inventory[idx] = 0;
}

void Character::use(int idx, Character& target) {
  if (this->inventory[idx]) {
    this->inventory[idx]->use(target);
  }
}
