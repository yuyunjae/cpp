#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <algorithm>

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
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
    Fixed &operator=(const Fixed &other);

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed &operator+(const Fixed &other) const;
    Fixed &operator-(const Fixed &other) const;
    Fixed &operator*(const Fixed &other) const;
    // Fixed &operator++(void);  // 전위 연산자
    // Fixed &operator--(void);
    // Fixed &operator++(int);  // 후위 연산자
    // Fixed &operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &me);

#endif
