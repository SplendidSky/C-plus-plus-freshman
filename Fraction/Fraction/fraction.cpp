#include "fraction.h"

#include <iostream>
#include <cmath>

using namespace std;

int fraction::gcd(const int &c, const int &d) const {
    auto a = c;
    auto b = d;
    int f = a % b;
    while (f) {
        a = b;
        b = f;
        f = a % b;
    }
    return abs(b);
}
void fraction::simp() {
    int g = gcd(_numerator, _denominator);
    if (!g)
        return;
    _numerator /= g;
    _denominator /= g;
}
fraction::fraction(const int &num, const int &deno) {
    _numerator = abs(num);
    _denominator = abs(deno);
    if (num < 0)
        _numerator = -_numerator;
    if (deno < 0)
        _numerator = -_numerator;
}
fraction::fraction(const fraction &f) : _numerator(f._numerator), _denominator(f._denominator) {}
void fraction::operator=(const fraction &f) {
    this->_denominator = f._denominator;
    this->_numerator = f._numerator;
}
fraction fraction::operator+(const fraction &f) const {
    int g = gcd(_denominator, f._denominator);
    long long deno =  _denominator * f._denominator / g;
    long long num = deno / _denominator * _numerator + deno / f._denominator * f._numerator;
    fraction r(num, deno);
    r.simp();
    return r;
}
fraction fraction::operator-(const fraction &f) const {
    int g = gcd(_denominator, f._denominator);
    long long deno =  1LL * _denominator * f._denominator / g;
    long long num = 1LL * deno / _denominator * _numerator - deno / f._denominator * f._numerator;
    fraction r(num, deno);
    r.simp();
    return r;
}
fraction fraction::operator*(const fraction &f) const {
    long long deno = 1LL * _denominator * f._denominator;
    long long num = 1LL * _numerator * f._numerator;
    long long res = 1;
    auto a = deno;
    auto b = num;
    long long c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    res = abs(b);
    num /= res;
    deno /= res;
    return fraction(num, deno);
}
fraction fraction::operator/(const fraction &f) const {
    long long deno = 1LL * _denominator * f._numerator;
    long long num = 1LL * _numerator * f._denominator;
    long long res = 1;
    auto a = deno;
    auto b = num;
    long long c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    res = abs(b);
    num /= res;
    deno /= res;
    return fraction(num, deno);
}
void fraction::operator+=(const fraction &f) {
    (*this) = (*this) + f;
}
void fraction::operator-=(const fraction &f) {
    (*this) = (*this) - f;
}
void fraction::operator*=(const fraction &f) {
    (*this) = (*this) * f;
}
void fraction::operator/=(const fraction &f) {
    (*this) = (*this) / f;
}
bool fraction::operator==(const fraction &f) const {
    fraction a(*this), b(f);
    a.simp();
    b.simp();
    return a._denominator == b._denominator && a._numerator == b._numerator;
}
bool fraction::operator!=(const fraction &f) const {
    fraction a(*this), b(f);
    a.simp();
    b.simp();
    return a._denominator != b._denominator || a._numerator != b._numerator;
}
bool fraction::operator<(const fraction &f) const {
    fraction a(*this), b(f);
    a.simp();
    b.simp();
    int g = gcd(a._denominator, b._denominator);
    long demo;
    if (!g)
        demo = a._denominator * b._denominator;
    else
        demo = a._denominator * b._denominator / g;
    return demo / a._denominator * a._numerator < demo / b._denominator * b._numerator;
}
bool fraction::operator>(const fraction &f) const {
    fraction a(*this), b(f);
    a.simp();
    b.simp();
    int g = gcd(a._denominator, b._denominator);
    long demo;
    if (!g)
        demo = a._denominator * b._denominator;
    else
        demo = a._denominator * b._denominator / g;
    return demo / a._denominator * a._numerator > demo / b._denominator * b._numerator;
}
bool fraction::operator<=(const fraction &f) const {
    fraction a(*this), b(f);
    a.simp();
    b.simp();
    int g = gcd(a._denominator, b._denominator);
    long demo;
    if (!g)
        demo = a._denominator * b._denominator;
    else
        demo = a._denominator * b._denominator / g;
    return demo / a._denominator * a._numerator <= demo / b._denominator * b._numerator;
}
bool fraction::operator>=(const fraction &f) const {
    fraction a(*this), b(f);
    a.simp();
    b.simp();
    int g = gcd(a._denominator, b._denominator);
    long demo;
    if (!g)
        demo = a._denominator * b._denominator;
    else
        demo = a._denominator * b._denominator / g;
    return demo / a._denominator * a._numerator >= demo / b._denominator * b._numerator;
}
std::istream & operator>>(std::istream &is, fraction &f) {
    int n, d;
    is >> n >> d;
    f = fraction(n, d);
    return is;
}
std::ostream & operator<<(std::ostream &os, const fraction &f) {
    if (f._denominator == 0)
        os << "NaN";
    else if (f._denominator == 1)
        os << f._numerator;
    os << f._numerator << "/" << f._denominator;
    return os;
}
