#ifndef PERSONALASSISTANT_H
#define PERSONALASSISTANT_H
#include "Event.h"
#include "Task.h"
#include <vector>

using std::vector;

namespace PersonalAssistant {
	class PersonalAssistant {
	private:
		vector<Event::event> events;
		vector<Task::task> tasks;
	public:
		void listTodos() const;
		void listEvents() const;
		void listTasks() const;
		void addTodo();
		bool deleteDone();
	};
}
#endif