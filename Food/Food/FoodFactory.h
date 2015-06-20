#include "Food.h"

#include <iostream>
#include <string>

using namespace std;

class FoodFactory : public Food, public McChicken, public Chips {
public:
    Food* getFood(const string &name) {
        if (name == "McChicken")
            return new McChicken();
        else if (name == "Chips")
            return new Chips();
        cout << "Sorry, we don't have that kind of food." << endl;
        return NULL;
    }
};
