#pragma once
#include <cmath>

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
};
