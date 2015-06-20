#include <iostream>
#include <string>

using namespace std;

class Object {
public:
    virtual int test() { return 0; }
};
class Animal : public Object {
public:
    virtual int test() { return 1; }
};
class Dog : public Animal {
public:
    virtual int test() { return 2; }
};
class Cat : public Animal {
public:
    virtual int test() { return 3; }
};
class Vehicle : public Object {
public:
    virtual int test() { return 4; }
};
class Bus : public Vehicle {
public:
    virtual int test() { return 5; }
};
class Car : public Vehicle {
public:
    virtual int test() { return 6; }
};

string instanceOf(Object *obj) {
    if (obj) {
        if (obj->test() == 0)
            return "Object";
        else if (obj->test() == 1)
            return "Animal";
        else if (obj->test() == 2)
            return "Dog";
        else if (obj->test() == 3)
            return "Cat";
        else if (obj->test() == 4)
            return "Vehicle";
        else if (obj->test() == 5)
            return "Bus";
        else if (obj->test() == 6)
            return "Car";
    }
    return "NULL";
}
