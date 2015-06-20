#ifndef __shape__shape__
#define __shape__shape__

#include <iostream>
using namespace std;
//  声明抽象基类Shape
class Shape {
public:
    virtual float area()const { return 0.0; }  //  虚函数
    virtual float volume()const { return 0.0; }  //  虚函数
    virtual void shapeName()const = 0;  //  纯虚函数
};
#endif /* defined(__shape__shape__) */
