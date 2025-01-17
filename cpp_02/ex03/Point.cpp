#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::~Point() {};

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

Point &Point::operator=(const Point &other) {  // ?? const ..
  if (this == &other) return *this;
  std::cout << "can't change const variables\n";
  return *this;
}

const Fixed &Point::getX(void) const { return this->x; }

const Fixed &Point::getY(void) const { return this->y; }
