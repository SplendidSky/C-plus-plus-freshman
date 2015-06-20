#include <iostream>
using namespace std;
#include "cylinder.h"
int main() {
    Point point(3.2, 4.5);
    Circle circle(2.4, 1.2, 5.6);
    Cylinder cylinder(3.5, 6.4, 5.2, 10.5);
    point.shapeName();
    cout << point << endl;
    circle.shapeName();
    cout << circle << endl;
    cylinder.shapeName();
    cout << cylinder << endl << endl;
    Shape *pt;
    pt = &point;
    pt->shapeName();
    cout << "x=" << point.getX() << ",y="
        << point.getY() << "\narea=" << pt->area()
        << "\nvolume=" << pt->volume() << "\n\n";
    pt = &circle;
    pt->shapeName();
    cout << "x=" << circle.getX() << ",y=" <<
        circle.getY() << "\narea=" << pt->area() << "\nvolume="
        << pt->volume() << "\n\n";
    pt = &cylinder;
    pt->shapeName();
    cout << "x=" << cylinder.getX() << ",y="
        << cylinder.getY() << "\narea=" << pt->area()
        << "\nvolume=" << pt->volume() << "\n\n";
    return 0;
}
