#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {}

std::string const& Weapon::getType() { return this->type; }
void Weapon::setType(const std::string& str) { this->type = str; }
