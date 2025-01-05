#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
 private:
  std::string type;

 public:
  Weapon(const std::string& type);
  ~Weapon();
  std::string const& getType();
  void setType(const std::string& str);
};

#endif
