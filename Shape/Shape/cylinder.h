#ifndef shape_cylinder_h
#define shape_cylinder_h
#include "circle.h"
class Cylinder :public Circle {
public:
    Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
    void setHeight(float h);
    virtual float area() const;
    virtual float volume() const;
    virtual void shapeName() const;
    friend ostream& operator <<(ostream&, const Cylinder&);
protected:
    float height;
};
#endif
