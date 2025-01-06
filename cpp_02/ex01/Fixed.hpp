#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int value;
  static const int fractionalBit;

 public:
  Fixed();
  // Fixed(const int value);
  // Fixed(const float value);
  ~Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const raw);

  // float toFloat(void) const;
  // int toInt(void) const;

  // std::ofstream &operator<<(std::ofstream out, const Fixed &me); // 이거 아닌
  // 듯
};

#endif
