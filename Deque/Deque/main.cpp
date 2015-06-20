#include <iostream>
#include <fstream>
#include "myDeque.h"
using namespace std;
int main() {
    myDeque * q1 = new myDeque, *q2;
    int n, p, x;
    for (std::cin >> n; n > 0; --n) {
        std::cin >> p;
        if (p == 0)
            std::cout << q1->getSize() << std::endl;
        else if (p == 1)
        if (q1->empty())
            std::cout << "empty" << std::endl;
        else
            std::cout << q1->head() << std::endl;
        else if (p == 2)
        if (q1->empty())
            std::cout << "empty" << std::endl;
        else
            std::cout << q1->tail() << std::endl;
        else if (p == 3) {
            std::cin >> x;
            q1->push_front(x);
        }
        else if (p == 4) {
            std::cin >> x;
            q1->push_back(x);
        }
        else if (p == 5)
        if (q1->empty())
            std::cout << "empty" << std::endl;
        else
            q1->pop_front();
        else
        if (q1->empty())
            std::cout << "empty" << std::endl;
        else
            q1->pop_back();
    }
    q2 = new myDeque(*q1);
    delete q1;
    while (q2->getSize()) {
        std::cout << q2->head() << std::endl;
        q2->pop_front();
    }
    delete q2;
    return 0;
}
