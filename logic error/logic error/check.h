#include <string>
#include <stdexcept>
#include <iostream>

bool check_negative(int num) {
    if (num < 0)
        throw std::logic_error("Not a negative number");
    else
        std::cout << "Negative number";
}
