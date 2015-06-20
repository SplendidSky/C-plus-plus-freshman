#include <iostream>
#include "Food.h"
#include "FoodFactory.h"

using namespace std;

int main() {
    Food *mcChicken = FoodFactory::getFood("McChicken");
    Food *chips = FoodFactory::getFood("Chips");
    Food *eggs = FoodFactory::getFood("Eggs");

    if (mcChicken != NULL) {
        mcChicken->get();
        delete mcChicken;
    }
    if (chips != NULL) {
        chips->get();
        delete chips;
    }
    if (eggs != NULL) {
        eggs->get();
    }

    return 0;
}