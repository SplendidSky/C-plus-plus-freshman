#include "circle.h"
#define Pi 3.14159

Circle::Circle(float x, float y, float r) : Point(x, y) { radius = r; }

void Circle::setRadius(float r) { radius = r; }
float Circle::getRadius() const { return radius; }

float Circle::area() const {
    return Pi * radius * radius;
}

void Circle::shapeName() const {
    cout << "Circle:";
}

ostream &operator<<(ostream &os, const Circle &c) {
    cout << "[" << c.x << "," << c.y << "]" << ", r=" << c.radius;
}
