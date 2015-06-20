#include <iostream>

using namespace std;

template <typename T>
class Foobar {
public:
    Foobar(T _data) : data(_data) {}
    friend ostream &operator<<(ostream &os, Foobar const &fb) {
        return os << fb.data;
    }
private:
    T data;
};