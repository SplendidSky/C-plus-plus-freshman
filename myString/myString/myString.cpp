#pragma warning(disable:4996)
#include "myString.h"
#include <iostream>
#include <stdio.h>

using std::istream;
using std::ostream;

myString::myString() {
    _data = nullptr;
    _length = 0;
};
myString::myString(const char *c) {
    int size = strlen(c);
    _data = new char[size + 1];
    strncpy(_data, c, strlen(c) + 1);
    _length = size;
}
myString::myString(const myString &s) {
    int size = s._length;
    _data = new char[size + 1];
    strncpy(_data, s._data, strlen(s._data) + 1);
    _length = size;
}
myString::~myString() {
    if (_data != nullptr)
        delete[] _data;
    _data = nullptr;
}
void myString::clear() {
    if (_data != nullptr)
        delete[] _data;
    _data = nullptr;
    _length = 0;
}
const char *myString::c_str() const {
    return _data;
}
unsigned myString::length() const {
    return _length;
}
void myString::operator=(const char *c) {
    if (_data != nullptr) {
        delete[] _data;
        _data = nullptr;
    }
    _data = new char[strlen(c) + 1];
    strncpy(_data, c, strlen(c) + 1);
    _length = strlen(c);
}
void myString::operator=(const myString &s) {
    if (_data != nullptr) {
        delete[] _data;
        _data = nullptr;
    }
    _data = new char[s._length + 1];
    strncpy(_data, s._data, strlen(s._data) + 1);
    _length = strlen(s._data);
}
char myString::operator[](const unsigned &index) const {
    return _data[index];
}
char &myString::operator[](const unsigned &index) {
    return _data[index];
}
myString myString::operator+(const myString &a) const {
    myString temp;
    temp._length = a._length + _length;
    temp._data = new char[temp._length + 1];
    strncpy(temp._data, _data, _length + 1);
    strncat(temp._data, a._data, temp._length + 1);
    return temp;
}
myString myString::operator+(const char *s) const {
    myString temp;
    temp._length = strlen(s) + _length;
    temp._data = new char[temp._length + 1];
    strncpy(temp._data, _data, _length + 1);
    strncat(temp._data, s, temp._length + 1);
    return temp;
}
istream &operator>>(istream &is, myString &s) {
    if (s._data != nullptr) {
        delete[] s._data;
        s._data = nullptr;
    }
    auto c = new char[1000];
    is >> c;
    s._data = c;
    s._length = strlen(c);
    return is;
}
ostream &operator<<(ostream &os, const myString &s) {
    return os << s._data;
}
void myString::operator+=(const myString &s) {
    (*this) = (*this) + s;
}
void myString::operator+=(const char *c) {
    (*this) = (*this) + c;
}
bool myString::operator==(const myString &s) const {
    if (strcmp(this->_data, s._data) == 0)
        return true;
    return false;
}
bool myString::operator==(const char *c) const {
    if (strcmp(this->_data, c) == 0)
        return true;
    return false;
}
bool myString::operator!=(const myString &s) const {
    return !((*this) == s);
}
bool myString::operator!=(const char *c) const {
    return !((*this) == c);
}
bool myString::operator<(const myString &s) const {
    if (strcmp(this->_data, s._data) < 0)
        return true;
    return false;
}
bool myString::operator<(const char *c) const {
    if (strcmp(this->_data, c) < 0)
        return true;
    return false;
}
bool myString::operator<=(const myString &s) const {
    if (strcmp(this->_data, s._data) <= 0)
        return true;
    return false;
}
bool myString::operator<=(const char *c) const {
    if (strcmp(this->_data, c) <= 0)
        return true;
    return false;
}
bool myString::operator>(const myString &s) const {
    if (strcmp(this->_data, s._data) > 0)
        return true;
    return false;
}
bool myString::operator>(const char *c) const {
    if (strcmp(this->_data, c) > 0)
        return true;
    return false;
}
bool myString::operator>=(const myString &s) const {
    if (strcmp(this->_data, s._data) >= 0)
        return true;
    return false;
}
bool myString::operator>=(const char *c) const {
    if (strcmp(this->_data, c) >= 0)
        return true;
    return false;
}
myString operator+(const char *s, const myString &a) {
    myString temp;
    temp._length = strlen(s) + a._length;
    temp._data = new char[temp._length + 1];
    strncpy(temp._data, s, strlen(s) + 1);
    strncat(temp._data, a._data, temp._length + 1);
    return temp;

}
bool operator==(const char *c, const myString &s) {
    if (strcmp(c, s._data) == 0)
        return true;
    return false;
}
bool operator!=(const char *c, const myString &s) {
    return !(s == c);
}
bool operator<(const char *c, const myString &s) {
    if (strcmp(c, s._data) < 0)
        return true;
    return false;
}
bool operator<=(const char *c, const myString &s) {
    if (strcmp(c, s._data) <= 0)
        return true;
    return false;
}
bool operator>(const char *c, const myString &s) {
    if (strcmp(c, s._data) > 0)
        return true;
    return false;
}
bool operator>=(const char *c, const myString &s) {
    if (strcmp(c, s._data) >= 0)
        return true;
    return false;
}
