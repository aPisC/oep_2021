#pragma once
#include <cmath>
#include <iostream>

/*
  Koordináták: x, y
  konstruktor
  distance(Point)
*/

class Point
{
public:
  double _x, _y;

public:
  Point(double a = 0, double b = 0) : _x(a), _y(b) {}
  double distance(const Point &p) const
  {
    return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2));
  }

private:
  friend std::istream &operator>>(std::istream &is, Point &p);
  friend std::ostream &operator<<(std::ostream &os, Point &p);
};

inline std::istream &operator>>(std::istream &is, Point &p)
{
  is >> p._x >> p._y;
  return is;
}

inline std::ostream &operator<<(std::ostream &os, Point &p)
{
  os << "(" << p._x << "," << p._y << ")";
  return os;
}