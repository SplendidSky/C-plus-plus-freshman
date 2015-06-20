#ifndef shape_circle_h
#define shape_circle_h
#include "point.h"
class Circle : public Point {
public:
    Circle(float x = 0, float y = 0, float r = 0);
    void setRadius(float r);
    float getRadius() const;
    virtual float area() const;
    virtual void shapeName() const;
    friend ostream &operator << (ostream &, const Circle &);
protected:
    float radius;
};


#endif
