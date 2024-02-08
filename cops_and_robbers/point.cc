#include "point.h"
#include "fraction.h"

point::point(Fraction _x, Fraction _y)
{
    x = _x;
    y = _y;
}
point point::operator+(point rhs) { return point(x + rhs.x, y + rhs.y); }
point point::operator-(point rhs) { return point(x - rhs.x, y - rhs.y); }
point point::operator*(Fraction rhs) { return point(x * rhs, y * rhs); }
Fraction point::operator*(point rhs) { return x * rhs.y - y * rhs.x; }
point point::operator=(point rhs)
{
    x = rhs.x;
    y = rhs.y;

    return *this;
}

std::istream &operator>>(std::istream &is, point &p)
{
    char lPar, comma, rPar;
    Fraction x, y;

    is >> lPar >> x >> comma >> y >> rPar;

    p = point(x, y);

    return is;
}
std::ostream &operator<<(std::ostream &os, point p)
{
    os << '(' << p.getX() << ',' << p.getY() << ')';

    return os;
}
