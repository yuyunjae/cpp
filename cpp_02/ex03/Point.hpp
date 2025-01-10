#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 private:
  Fixed const x;
  Fixed const y;
  static Fixed crossProduct(Point const a, Point const b, Point const point);

 public:
  Point();
  Point(float const x, float const y);
  ~Point();
  Point(const Point &other);
  Point &operator=(const Point &other);

  const Fixed &getX(void) const;
  const Fixed &getY(void) const;

  static bool bsp(Point const a, Point const b, Point const c,
                  Point const point);
};

#endif
