#include "myDeque.h"

myDeque::myDeque() : _head(nullptr), _tail(nullptr), _size(0) {}
myDeque::myDeque(const myDeque &sou) {
    if (sou.empty()) {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
        return;
    }
    auto temp1 = sou._head;
    _tail = _head = new listNode(temp1->_x, nullptr, nullptr);
    auto temp2 = _head;
    temp1 = temp1->_succ;
    while (temp1) {
        temp2->_succ = new listNode(temp1->_x, temp2, nullptr);
        temp2 = temp2->_succ;
        temp1 = temp1->_succ;
    }
    _tail = temp2;
	_size = sou._size;
}
myDeque::~myDeque() {
    if (!empty()) {
        auto temp = _head;
        while (temp) {
            _head = _head->_succ;
            delete temp;
            temp = _head;
        }
    }
    else
        _tail = _head = nullptr;
}
int myDeque::getSize()const {
    return _size;
}
bool myDeque::empty()const {
    return _size <= 0;
}
int myDeque::head()const {
    return _head->_x;
}
int myDeque::tail()const {
    return _tail->_x;
}
void myDeque::push_front(const int &n) {
    if (!empty()) {
        auto temp = new listNode(n, nullptr, _head);
        _head->_prep = temp;
        _head = temp;
        ++_size;
    }
    else {
        _head = new listNode(n, nullptr, nullptr);
        _tail = _head;
        ++_size;
    }
}
void myDeque::push_back(const int &n) {
    if (!empty()) {
        auto temp = new listNode(n, _tail, nullptr);
        _tail->_succ = temp;
        _tail = temp;
        ++_size;
    }
    else {
        _head = new listNode(n, nullptr, nullptr);
        _tail = _head;
        ++_size;
    }
}
bool myDeque::pop_front() {
    if (!empty()) {
        if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            --_size;
            return true;
        }
        auto temp = _head;
        _head = _head->_succ;
        _head->_prep = nullptr;
        delete temp;
        --_size;
        if (_size == 0) {
            _head = nullptr;
            _tail = nullptr;
        }
        return true;
    }
    return false;
}
bool myDeque::pop_back() {
    if (!empty()) {
        if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            --_size;
            if (_size == 0) {
                _head = nullptr;
                _tail = nullptr;
            }
            return true;
        }
        auto temp = _tail;
        _tail = _tail->_prep;
        _tail->_succ = nullptr;
        delete temp;
        --_size;
        if (_size == 0) {
            _head = nullptr;
            _tail = nullptr;
        }
        return true;
    }
    return false;
}
