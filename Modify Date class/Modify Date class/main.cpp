#include <iostream>
#include <string>
#include "Date.h"
#include "IllegalSubscriptException.h"
using namespace std;


int main() {
	int y, m, d;
	string subscript;
	int newValue;
	const char leap[2][20] = { "Common year", "Leap year" };
	cin >> y >> m >> d;
	Date date(y, m, d);

	try {
		cout << date.getYear() << "-" << date.getMonth()
			<< "-" << date.getDay() << ": "
			<< leap[Date::isLeapYear(date["year"])] << endl;
		cin >> subscript >> newValue;
		cout << "Current " << subscript << " is " << date[subscript] << endl;
		date[subscript] = newValue;
		cout << "Set " << subscript << " to " << newValue << endl;
		cout << date.getYear() << "-" << date.getMonth()
			<< "-" << date.getDay() << ": "
			<< leap[Date::isLeapYear(date["year"])] << endl;
	}
	catch (IllegalSubscriptException ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
