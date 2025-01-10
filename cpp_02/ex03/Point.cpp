#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::~Point() {};

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

Point &Point::operator=(const Point &other) {
  //
}

const Fixed &Point::getX(void) const { return this->x; }

const Fixed &Point::getY(void) const {
  //
}
