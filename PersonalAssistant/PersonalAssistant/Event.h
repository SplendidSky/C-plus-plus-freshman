#include <iostream>
#include <string>
#include "Time.h"

using std::string;

namespace Event {
	class event {
	private:
		string name;
		string location;
		string notes;
		Time::time time;
	public:
		string getEvent() const { return name; }
		Time::time getTime() const { return time; }
		string getLocation() const { return location; }
		string getNotes() const { return notes; }

		bool setEvent(string e);
		bool setLocation(string l);
		bool setNotes(string n);
		bool setTime(string t);

		friend std::ostream &operator<<(std::ostream &os, Event::event e);
	};
}
