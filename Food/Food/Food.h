#ifndef __Food_Factory__Food__
#define __Food_Factory__Food__

#include <iostream>
using namespace std;
class Food {
public:
    Food() {}
    virtual ~Food() {}
    virtual void get() = 0;
};

class McChicken : public Food {
public:
    McChicken() {}
    virtual ~McChicken() {}
    void get() {
        cout << "You should pay $10." << endl;
    }
};

class Chips : public Food {
public:
    Chips() {}
    virtual ~Chips() {}
    void get() {
        cout << "The chips costs $5." << endl;
    }
};

#endif
