#include "derived.h"

using namespace std;

Derived::Derived(const int * arr, int _size, int _value) : Base(_value) {
    size = _size;
    data = new int[_size];
    for (int i = 0; i < _size; i++)
        data[i] = arr[i];
}
Derived::Derived(const Derived& D) : Base(D.getValue()) {
    size = D.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = D.data[i];
}
Derived& Derived::operator=(const Derived& D) {
    if (this == &D) return *this;
    size = D.size;
    data = new int[size];
    Base::operator=(D);
    for (int i = 0; i < size; i++)
        data[i] = D.data[i];
    return *this;
}
Derived::~Derived() {
    delete[] data;
}
