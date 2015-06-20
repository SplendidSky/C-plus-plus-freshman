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

//δ���õ��ж�ʱ�������Ƿ�Ϸ��ĺ���

//bool Time::time::setTime(string time) {
//
//	//��ȡ����ʱ�������
//	istringstream is(time);
//	int year_or_hour, month_or_minute, date_or_second;
//	char firstSeperate, secondSeperate;
//	is >> year_or_hour >> firstSeperate >> month_or_minute >> secondSeperate >> date_or_second;
//
//	// ��ȡϵͳ��ǰʱ��
//	time_t now;
//	now = std::time(nullptr);
//	struct tm *timeinfo;
//	timeinfo = localtime(&now);
//
//	//��ǰ�����ʾʱ��
//	if (firstSeperate == secondSeperate && firstSeperate == ':') {
//		//ȷ������ʱ��Ϸ�
//		if (year_or_hour >= 24 || year_or_hour < 0 ||
//			month_or_minute >= 60 || month_or_minute < 0 ||
//			date_or_second >= 60 || date_or_second < 0) {
//			cout << "�����ʱ���ʽ" << endl;
//			return false;
//		}
//		else {
//			//�����δ�������ڣ�����������Ϊϵͳ��ǰ����
//			if (year == NOTSET) {
//				year = timeinfo->tm_year + 1900;
//				month = timeinfo->tm_mon + 1;
//				date = timeinfo->tm_mday;
//			}
//
//			//�������Ϊ���죬ȷ������ʱ���ڵ�ǰʱ��֮��
//			if (year == timeinfo->tm_year + 1900 &&
//				month == timeinfo->tm_mon + 1 &&
//				date == timeinfo->tm_mday) {
//				if (!(year_or_hour < timeinfo->tm_hour ||
//					(year_or_hour == timeinfo->tm_hour &&
//					month_or_minute < timeinfo->tm_min) ||
//					(year_or_hour == timeinfo->tm_hour &&
//					month_or_minute == timeinfo->tm_min &&
//					date_or_second <= timeinfo->tm_sec))) {
//					cout << "�����ʱ�䣬��ȷ��ʱ���ڵ�ǰʱ��֮��" << endl;
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
//	//��ǰ�����ʾ����
//	else if (firstSeperate == secondSeperate && firstSeperate == '-') {
//
//		//ȷ���������ںϷ�
//		if (!(year_or_hour < timeinfo->tm_year + 1900 ||
//			(year_or_hour == timeinfo->tm_year + 1900 &&
//			month_or_minute < timeinfo->tm_mon + 1) ||
//			(year_or_hour == timeinfo->tm_year + 1900 &&
//			month_or_minute == timeinfo->tm_mon + 1 &&
//			date_or_second <= timeinfo->tm_mday))) {
//			cout << "���Ϸ�������" << endl;
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
//		cout << "��Ч������" << endl;
//		return false;
//	}
//}


//��ǰ���õ��ж�ʱ�������Ƿ�Ϸ��ĺ�����������ǿ׳��ֻ�Ǽ򵥵��жϸ�ʽ
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
		cout << "��ʽΪ����.��.�� �� ��-��-�� �� ʱ:��:��" << endl;
		return false;
	}
}
