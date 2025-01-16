#include "Character.hpp"

const int Character::maxInventory = 4;

Character::Character() : name("") {
  std::cout << "Character Default Constructor called\n";
  for (int i = 0; i < this->maxInventory; i++) inventory[i] = 0;
  this->garbage = 0;
}

Character::Character(const std::string& name) : name(name) {
  std::cout << "Character Constructor called\n";
  for (int i = 0; i < this->maxInventory; i++) inventory[i] = 0;
  this->garbage = 0;
}

Character::~Character() {
  std::cout << "Character  Destructor called\n";
  for (int i = 0; i < this->maxInventory; i++) {
    if (this->inventory[i]) {
      delete this->inventory[i];
    }
  }
  this->cleanGarbage();
}

void Character::AddGarbage(AMateria* m) {
  tGarbage* temp;

  temp = this->garbage;
  if (!temp) {
    temp = new tGarbage;
    temp->next = 0;
    temp->materia = m;
    return;
  }
  while (temp->next) temp = temp->next;
  temp->next = new tGarbage;
  temp->next->next = 0;
  temp->next->materia = m;
}

void Character::cleanGarbage() {
  tGarbage* temp;

  temp = this->garbage;
  this->garbage = 0;
  if (!temp) return;
  while (this->garbage->next) {
    delete temp->materia;
    this->garbage = this->garbage->next;
    delete temp;
    temp = this->garbage;
  }
  delete temp->materia;
  delete temp;
}

Character::tGarbage* Character::cloneGarbage() const {
  tGarbage* temp = 0;
  tGarbage* copyGarbage = 0;
  tGarbage* node = this->garbage;
  tGarbage* newNode = 0;
  while (node) {
    newNode = new tGarbage;
    newNode->materia = node->materia->clone();
    temp->next = newNode;
    if (!copyGarbage) copyGarbage = temp->next;
    node = node->next;
    temp = temp->next;
  }
  return copyGarbage;
}

Character::Character(const Character& other) {
  std::cout << "Character Copy Constructor called\n";
  this->name = other.name;
  for (int i = 0; i < this->maxInventory; i++) {
    if (other.inventory[i]) {
      this->inventory[i] = other.inventory[i]->clone();
    }
  }
  this->garbage = other.cloneGarbage();
}

Character& Character::operator=(const Character& other) {
  AMateria* temp;
  std::cout << "Character Copy assignment operator called\n";
  if (this != &other) {
    this->name = other.name;
    for (int i = 0; i < this->maxInventory; i++) {
      if (other.inventory[i]) {
        temp = other.inventory[i]->clone();
        if (this->inventory[i]) delete this->inventory[i];
        this->inventory[i] = temp;
      }
    }
    this->cleanGarbage();
    this->garbage = other.cloneGarbage();
  }
  return *this;
}

std::string const& Character::getName() const { return this->name; }

void Character::equip(AMateria* m) {
  for (int i = 0; i < this->maxInventory; i++) {
    if (!this->inventory[i]) {
      this->inventory[i] = m->clone();
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (this->inventory[idx]) {
    this->AddGarbage(this->inventory[idx]);
    this->inventory[idx] = 0;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (this->inventory[idx]) {
    this->inventory[idx]->use(target);
  }
}
