#include <cstdlib>
#include <algorithm>

template<typename T> class Array {
private:
    T _data[100];
    int _length;
public:
    Array() : _length(0) {}
    explicit Array(int length) : _length(length) {}
    Array(const Array& src) {
        _length = src._length;
        for (int i = 0; i < src._length; i++)
            _data[i] = src._data[i];
    }
    int getLength() { return _length; }
    Array& operator=(const Array& src) {
        _length = src._length;
        for (int i = 0; i < src._length; i++)
            _data[i] = src._data[i];
        return *this;
    }
    T& operator[](int index) {
        if (index < _length && index >= 0)
            return _data[index];
    }
    Array slice(int start, int end, int step) {
        Array a;
        if (step > 0) {
            for (int i = start, j = 0; i <= end; i += step, j++) {
                a._data[j] = this->_data[i];
                a._length++;
            }
        }
        else {
            for (int i = end, j = 0; i >= start; i += step, j++) {
                a._data[j] = this->_data[i];
                a._length++;
            }
        }
        return a;
    }
    void traverse(void(*visit)(T &t)) {
        for (int i = 0; i < _length; i++)
            (*visit)(this->_data[i]);
    }
};
