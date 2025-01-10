#include "Point.hpp"

Fixed Point::crossProduct(Point const a, Point const b, Point const point) {
  Fixed vec1X(b.getX() - a.getX());
  Fixed vec1Y(b.getY() - a.getY());
  Fixed vec2X(point.getX() - a.getX());
  Fixed vec2Y(point.getY() - a.getY());

  return (vec1X * vec2Y - vec1Y * vec2X);
}

bool Point::bsp(Point const a, Point const b, Point const c,
                Point const point) {
  Fixed first(a.crossProduct(a, b, point));
  Fixed second(b.crossProduct(b, c, point));
  Fixed third(c.crossProduct(c, a, point));

  if ((first > 0 && second > 0 && third > 0) ||
      (first < 0 && second < 0 && third < 0))
    return true;
  return false;
}
