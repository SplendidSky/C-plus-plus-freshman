#include "Conference.h"
#include <iostream>
#include <iomanip>

#define STANDARD_WIDTH 15    // 将标准输出宽度设置为15

using std::cout;
using std::setw;
using std::endl;

bool Conference::set_time(string _time) {
    time = _time;
    return true;
}

bool Conference::set_date(string _date) {
    date = _date;
    return true;
}

bool Conference::set_location(string _location) {
    location = _location;
    return true;
}

bool Conference::set_theme(string _theme) {
    theme = _theme;
    return true;

}

string Conference::get_time() const {
    return time;
}

string Conference::get_date() const {
    return date;
}

string Conference::get_location() const {
    return date;
}

string Conference::get_theme() const {
    return theme;
}

bool Conference::print_C() const {
    cout.setf(std::ios::left);
    cout << setw(STANDARD_WIDTH);
    cout << theme;
    cout << setw(STANDARD_WIDTH);
    cout << date;
    cout << setw(STANDARD_WIDTH);
    cout << time;
    cout << setw(STANDARD_WIDTH);
    cout << location;
    cout << endl;
    return true;
}

