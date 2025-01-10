#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : value(0) { std::cout << "Default constructor called\n"; }

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

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) this->value = other.getRawBits();
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

int Fixed::toInt(void) const { return (this->value >> this->fractionalBit); }

float Fixed::toFloat(void) const {
  return (float(this->value) / (1 << this->fractionalBit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &me) {
  out << me.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed &other) const {
  return (this->getRawBits() > other.getRawBits() ? true : false);
}

bool Fixed::operator<(const Fixed &other) const {
  return (this->getRawBits() < other.getRawBits() ? true : false);
}

bool Fixed::operator>=(const Fixed &other) const {
  return (this->getRawBits() >= other.getRawBits() ? true : false);
}

bool Fixed::operator<=(const Fixed &other) const {
  return (this->getRawBits() <= other.getRawBits() ? true : false);
}

bool Fixed::operator==(const Fixed &other) const {
  return (this->getRawBits() == other.getRawBits() ? true : false);
}

bool Fixed::operator!=(const Fixed &other) const {
  return (this->getRawBits() != other.getRawBits() ? true : false);
}

Fixed Fixed::operator+(const Fixed &other) const {
  //   Fixed fixed;
  //   fixed.setRawBits(this->getRawBits() + other.getRawBits());
  //   return fixed;
  return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
  //   Fixed fixed;
  //   fixed.setRawBits(this->getRawBits() - other.getRawBits());
  //   return fixed;
  return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
  return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
  if (other.getRawBits()) return (Fixed(this->toFloat() / other.toFloat()));
  std::cout << "division by zero error\n";
  return 0;
}

Fixed &Fixed::operator++(void) {  // 전위 연산자
  this->value++;
  return *this;
}
Fixed &Fixed::operator--(void) {
  this->value--;
  return *this;
}
Fixed Fixed::operator++(int) {  // 후위 연산자
  Fixed fixed(*this);
  this->value++;
  return fixed;
}
Fixed Fixed::operator--(int) {
  Fixed fixed(*this);
  this->value--;
  return fixed;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return ((b < a) ? b : a); }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return ((b < a) ? b : a);
}
Fixed &Fixed::max(Fixed &a, Fixed &b) { return ((a < b) ? b : a); }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return ((a < b) ? b : a);
}
