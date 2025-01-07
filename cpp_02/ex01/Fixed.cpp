#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called\n";
    this->value = value;
    if ((this->value >> (32 - this->fractionalBit) ^ 0) &&
        (this->value >> (32 - this->fractionalBit) ^
         ((1 << this->fractionalBit) - 1)))  // 이거 오버플로우 어캐하냐..
        std::cout << "overflow occur!\n";
    this->value = this->value << this->fractionalBit;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called\n";
    if (fabs(value) > fabs(value * (1 << this->fractionalBit)))
        std::cout << "overflow occur!\n";
    this->value = roundf(value * (1 << this->fractionalBit));
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called\n";
    this->value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called\n"; // 과제 예시 사진에서
    // 이거 주석처리 되어있는 듯
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called\n";
    this->value = raw;
}

int Fixed::toInt(void) const {
    return (this->value >> this->fractionalBit);
}

float Fixed::toFloat(void) const {
    return (float(this->value) / (1 << this->fractionalBit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &me) {
    out << me.toFloat();
    return out;
}