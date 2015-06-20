#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <string>

using std::string;

class Conference {
private:
    string date;    //会议日期
    string time;    //会议时间
    string location;   //会议地点
    string theme;    //会议主题
public:
    Conference() {}
    bool set_time(string _time);    //设置会议时间
    bool set_date(string _date);    //设置会议日期
    bool set_location(string _location);    //设置会议地点
    bool set_theme(string _theme);    //设置会议主题

    string get_time() const;    //返回会议时间
    string get_date() const;    //返回会议日期
	string get_location() const;    //返回会议地点
	string get_theme() const;    //返回会议主题

    bool print_C() const;		//打印会议
};

#endif