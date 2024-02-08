#include "fraction.h"
#include <iostream>

#ifndef _POINT_H
#define _POINT_H

class point
{
private:
    Fraction x, y;

public:
    point(Fraction _x = Fraction(), Fraction _y = Fraction());
    ~point() = default;

    point operator+(point rhs);
    point operator-(point rhs);
    Fraction operator*(point rhs);
    point operator*(Fraction rhs);
    point operator=(point rhs);

    Fraction getX() { return x; }
    Fraction getY() { return y; }
};

std::istream &operator>>(std::istream &, point &);
std::ostream &operator<<(std::ostream &, point);

#endif
