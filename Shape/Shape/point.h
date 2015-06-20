#ifndef shape_point_h
#define shape_point_h
#include "shape.h"
class Point : public Shape {
public:
    Point(float = 0, float = 0);
    void setPoint(float a, float b);
    float getX() const;
    float getY() const;
    virtual void shapeName() const;
    friend ostream & operator << (ostream &, const Point &);
protected:
    float x, y;
};


#endif
