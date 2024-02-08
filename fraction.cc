#include "fraction.h"
#include <numeric>

Fraction::Fraction(int32_t n, int32_t d) {
    if (d < 0) {
        d = -d;
        n = -n;
    }
    int32_t g = std::gcd(n, d);

    num = n / g;
    den = d / g;
}

Fraction Fraction::operator+(Fraction rhs) {
    int32_t s, t;

    s = num * rhs.den + den * rhs.num;
    t = den * rhs.den;

    return Fraction(s, t);
}

Fraction Fraction::operator-(Fraction rhs) {
    int32_t s, t;

    s = num * rhs.den - den * rhs.num;
    t = den * rhs.den;

    return Fraction(s, t);
}

Fraction Fraction::operator*(Fraction rhs) {
    int32_t s, t;

    s = num * rhs.num;
    t = den * rhs.den;

    return Fraction(s, t);
}

Fraction Fraction::operator/(Fraction rhs) {
    int32_t s, t;

    s = num * rhs.den;
    t = den * rhs.num;

    return Fraction(s, t);
}

Fraction Fraction::operator=(Fraction rhs) {
    num = rhs.num;
    den = rhs.den;

    return *this;
}

bool Fraction::operator==(Fraction rhs) {
    return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {
    return num != rhs.num || den != rhs.den;
}

bool Fraction::operator<(Fraction rhs) {
    return num * rhs.den < den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {
    return num * rhs.den > den * rhs.num;
}

bool Fraction::operator<=(Fraction rhs) {
    return num * rhs.den <= den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {
    return num * rhs.den >= den * rhs.num;
}

std::istream &operator>>(std::istream &is, Fraction &f) {
    int32_t n, d;
    char slash;

    is >> n >> slash >> d;

    f = Fraction(n, d);

    return is;
}

std::ostream &operator<<(std::ostream &os, Fraction f) {
    os << f.getNum() << " / " << f.getDen();

    return os;
}

