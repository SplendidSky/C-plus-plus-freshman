#ifndef __shape__shape__
#define __shape__shape__

#include <iostream>
using namespace std;
//  �����������Shape
class Shape {
public:
    virtual float area()const { return 0.0; }  //  �麯��
    virtual float volume()const { return 0.0; }  //  �麯��
    virtual void shapeName()const = 0;  //  ���麯��
};
#endif /* defined(__shape__shape__) */
