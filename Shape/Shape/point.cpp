#include "point.h"
#include <iostream>

using std::cout;

Point::Point(float _x, float _y) : x(_x), y(_y) {}

void Point::setPoint(float a, float b) {
    x = a;
    y = b;
}

float Point::getX() const {
    return x;
}
float Point::getY() const {
    return y;
}

void Point::shapeName() const {
    cout << "Point:";
}

ostream &operator<<(ostream &os, const Point &p) {
    cout << "[" << p.x << "," << p.y << "]";
}