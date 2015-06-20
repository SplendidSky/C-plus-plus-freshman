#ifndef TASK_H
#define TASK_H

#include <string>
#include "Time.h"

using std::string;

namespace Task {
	class task {
	private:
		string name;
		Time::time DDL;
		string notes;
	public:
		string getTask() { return name; }
		Time::time getDDL() { return DDL; }
		string getNotes() { return notes; }

		bool setTask(string t);
		bool setDDL(string d);
		bool setNotes(string n);

		friend std::ostream &operator<<(std::ostream &os, Task::task t);

	};
}

#endif