#pragma once
#include <iostream>
/*
  Középpont (Point), sugár
  Konstruktor
  contains(Point)
*/

class Circle
{
private:
  Point _c;
  double _r;

public:
  Circle() {}
  Circle(const Point &p, double d) : _c(p), _r(d) {}
  bool contains(const Point &p) const
  {
    return _c.distance(p) <= _r;
  }

private:
  friend std::ostream &operator<<(std::ostream &os, Circle &c);
};

inline std::ostream &operator<<(std::ostream &os, Circle &c)
{
  os << "[" << c._c << "," << c._r << "]";
  return os;
}