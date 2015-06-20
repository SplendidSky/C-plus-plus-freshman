#include "Event.h"
#include <iostream>
#include <iomanip>

#define STANDARD_WIDTH 15

bool Event::event::setEvent(string e) {
	if (e.find_first_not_of(" ") == string::npos)
		return false;
	name = e;
	return true;
}

bool Event::event::setLocation(string l) {
	if (l.find_first_not_of(" ") == string::npos)
		return false;
	location = l;
	return true;
}

bool Event::event::setNotes(string n) {
	notes = n;
	return true;
}

bool Event::event::setTime(string t) {
	return time.setTime(t);
}

std::ostream &Event::operator<<(std::ostream &os, Event::event e) {
	std::cout.setf(std::ios::left);
	std::cout.width(STANDARD_WIDTH);
	std::cout << e.getEvent();
	std::cout << e.getTime().getYear();
	std::cout << " - ";
	std::cout << e.getTime().getMonth();
	std::cout << " - ";
	std::cout << e.getTime().getDate();
	std::cout << " ";
	std::cout.width(STANDARD_WIDTH);
	std::cout << e.getLocation();
	std::cout.width(STANDARD_WIDTH);
	std::cout << e.getNotes();
	return os;
}