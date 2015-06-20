#ifndef DATE_H
#define DATE_H

#include <string>
#include "IllegalSubscriptException.h"
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int _year, int _month, int _day) :
		year(_year), month(_month), day(_day) {}
	int &operator[](string s) {
		if (s == "year")
			return year;
		else if (s == "month")
			return month;
		else if (s == "day")
			return day;
		else
			throw IllegalSubscriptException("Illegal Subscript Exception");
	}
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	static bool isLeapYear(int year);
};

bool Date::isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
#endif
