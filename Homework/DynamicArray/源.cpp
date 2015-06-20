#include <iostream>
#include "dynamicArray.h"
using namespace std;
void dynamic_array::cpy(int *a, const int *b, const unsigned &size) {
	unsigned i;
	for (i = 0; i < size; i++) {
		a[i] = b[i];
	}
}
void dynamic_array::grow() {
	int *p = new int[_size * 2 + 1];
	unsigned pSize = _size;
	_size = _size * 2;
	cpy(p, _data, pSize);
	for (unsigned i = pSize; i < _size; ++i)
		p[i] = 0;
	delete[] _data;
	_data = p;
}
dynamic_array::dynamic_array(const unsigned &size, const int &a) {
	_size = size;
	int *p = new int[size + 1];
	for (unsigned i = 0; i < _size; i++) {
		p[i] = a;
	}
	_data = p;
}
dynamic_array::dynamic_array(const int *a, const unsigned &size) {
	_data = new int[size + 1];
	_size = size;
	cpy(_data, a, size);
}
dynamic_array::dynamic_array(const std::vector<int> &a) {
	_size = a.size();
	if (_size > 0) {
		_data = new int[_size];
		for (unsigned i = _size - 1; i > 0; --i)
			_data[i] = a[i];
		_data[0] = a[0];
	}
}
dynamic_array::dynamic_array(const dynamic_array &a) {
	_size = a._size;
	_data = new int[_size];
	cpy(_data, a._data, _size);
}
dynamic_array::~dynamic_array() {
	if (_data) {
		delete[] _data;
	}
}
int dynamic_array::getSize() const {
	return _size;
}
int & dynamic_array::operator[](const unsigned &a) {
	if (a >= _size) {
		grow();
	}
	return _data[a];
}
int dynamic_array::operator[](const unsigned &a) const {
	return _data[a];
}
std::ostream & operator<<(std::ostream &a, const dynamic_array &b) {
	if (b._size > 0) {
		a << b[0];
		for (int i = 1; i < b._size; ++i)
			a << ' ' << b[i];
	}
	return a;
}
