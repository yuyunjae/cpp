#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
   private:
    int value;
    static const int fractionalBit;

   public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);

    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &me);

#endif
