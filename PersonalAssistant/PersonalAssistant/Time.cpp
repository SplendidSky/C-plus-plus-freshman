#pragma warning(disable:4996)
#define NOTSET -1
#include "Time.h"
#include <sstream>
#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;

//未采用的判断时间输入是否合法的函数

//bool Time::time::setTime(string time) {
//
//	//获取输入时间或日期
//	istringstream is(time);
//	int year_or_hour, month_or_minute, date_or_second;
//	char firstSeperate, secondSeperate;
//	is >> year_or_hour >> firstSeperate >> month_or_minute >> secondSeperate >> date_or_second;
//
//	// 获取系统当前时间
//	time_t now;
//	now = std::time(nullptr);
//	struct tm *timeinfo;
//	timeinfo = localtime(&now);
//
//	//当前输入表示时间
//	if (firstSeperate == secondSeperate && firstSeperate == ':') {
//		//确保输入时间合法
//		if (year_or_hour >= 24 || year_or_hour < 0 ||
//			month_or_minute >= 60 || month_or_minute < 0 ||
//			date_or_second >= 60 || date_or_second < 0) {
//			cout << "错误的时间格式" << endl;
//			return false;
//		}
//		else {
//			//如果尚未设置日期，将日期设置为系统当前日期
//			if (year == NOTSET) {
//				year = timeinfo->tm_year + 1900;
//				month = timeinfo->tm_mon + 1;
//				date = timeinfo->tm_mday;
//			}
//
//			//如果日期为当天，确保设置时间在当前时间之后
//			if (year == timeinfo->tm_year + 1900 &&
//				month == timeinfo->tm_mon + 1 &&
//				date == timeinfo->tm_mday) {
//				if (!(year_or_hour < timeinfo->tm_hour ||
//					(year_or_hour == timeinfo->tm_hour &&
//					month_or_minute < timeinfo->tm_min) ||
//					(year_or_hour == timeinfo->tm_hour &&
//					month_or_minute == timeinfo->tm_min &&
//					date_or_second <= timeinfo->tm_sec))) {
//					cout << "错误的时间，请确保时间在当前时间之后" << endl;
//					return false;
//				}
//			}
//		}
//
//		hour = year_or_hour;
//		minute = month_or_minute;
//		second = date_or_second;
//	}
//
//	//当前输入表示日期
//	else if (firstSeperate == secondSeperate && firstSeperate == '-') {
//
//		//确保输入日期合法
//		if (!(year_or_hour < timeinfo->tm_year + 1900 ||
//			(year_or_hour == timeinfo->tm_year + 1900 &&
//			month_or_minute < timeinfo->tm_mon + 1) ||
//			(year_or_hour == timeinfo->tm_year + 1900 &&
//			month_or_minute == timeinfo->tm_mon + 1 &&
//			date_or_second <= timeinfo->tm_mday))) {
//			cout << "不合法的日期" << endl;
//			return false;
//		}
//		else {
//			year = year_or_hour;
//			month = month_or_minute;
//			date = date_or_second;
//		}
//
//		return true;
//	}
//
//	else {
//		cout << "无效的输入" << endl;
//		return false;
//	}
//}


//当前采用的判断时间输入是否合法的函数，但不够强壮，只是简单地判断格式
bool Time::time::setTime(string time) {
	istringstream is(time);
	int y_h, m_m, d_s;
	char spr1, spr2;
	is >> y_h >> spr1 >> m_m >> spr2 >> d_s;
	if ((spr1 == '.' && spr2 == '.') || (spr1 == '-' && spr2 == '-')) {
		year = y_h;
		month = m_m;
		date = d_s;
		return true;
	}
	else if (spr1 == ':' && spr2 == ':') {
		hour = y_h;
		minute = m_m;
		second = d_s;
		return true;
	}
	else {
		cout << "格式为：年.月.日 或 年-月-日 或 时:分:秒" << endl;
		return false;
	}
}
