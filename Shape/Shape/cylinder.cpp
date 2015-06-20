#include "cylinder.h"
#define Pi 3.14159

Cylinder::Cylinder(float x, float y, float r, float h) : Circle(x, y, r) { height = h; }

void Cylinder::setHeight(float h) { height = h; }

float Cylinder::area() const {
    return 2 * Circle::area() + 2 * Pi * radius * height;
}

float Cylinder::volume() const {
    return Circle::area() * height;
}

void Cylinder::shapeName() const {
    cout << "Cylinder:";
}

ostream &operator<<(ostream &os, const Cylinder &c) {
    cout << "[" << c.x << "," << c.y << "]" << ", r=" << c.radius << ", h=" << c.height;
}
