#include "Task.h"
#include <iostream>
#include <iomanip>

#define STANDARD_WIDTH 15

bool Task::task::setTask(string t) {
	if (t.find_first_not_of(" ") == string::npos)
		return false;
	name = t;
	return true;
}


bool Task::task::setNotes(string n) {
	notes = n;
	return true;
}

bool Task::task::setDDL(string d) {
	return DDL.setTime(d);
}

std::ostream &Task::operator<<(std::ostream &os, Task::task t) {
	std::cout.setf(std::ios::left);
	std::cout.width(STANDARD_WIDTH);
	std::cout << t.getTask();
	std::cout << t.getDDL().getYear();
	std::cout << " - ";
	std::cout << t.getDDL().getMonth();
	std::cout << " - ";
	std::cout << t.getDDL().getDate();
	std::cout << " ";
	std::cout.width(STANDARD_WIDTH);
	std::cout << t.getNotes();
	return os;
}
