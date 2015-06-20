#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>

using std::string;

namespace Time {
	class time {
	private:  
		unsigned date;
		unsigned month;
		unsigned year;
		unsigned hour;
		unsigned minute;
		unsigned second;
	public:

		time() : year(-1), month(-1), date(-1), hour(-1), minute(-1), second(-1) {}

		bool setTime(string time);

		unsigned getYear() const { return year; }
		unsigned getMonth() const { return month; }
		unsigned getDate() const { return date; }
		unsigned getHour() const { return hour; }
		unsigned getMinute() const { return minute; }
		unsigned getSecond() const { return second; }

	};
}
#endif