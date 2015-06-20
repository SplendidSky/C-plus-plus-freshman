#include "ConferenceArrangement.h"
#include <iostream>
#include <vector>
#include <iomanip>

#define STANDARD_WIDTH 15    // 将标准输出宽度设置为15

using std::setw;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

void CA::print_CA() const {
	int i = 0;
	for (vector<Conference>::const_iterator it = Cs.cbegin(); it != Cs.cend(); it++) {
		cout.setf(std::ios::left);
		cout << setw(STANDARD_WIDTH);
		cout << ++i;
		it->print_C();
	}
}

bool CA::add_C() {
	string _time, _date, _location, _theme;
	Conference C;
	do {
		cout << "会议主题：";
		cin >> _theme;
	} while (!C.set_theme(_theme));
	do {
		cout << "日期：";
		cin >> _date;
	} while (!C.set_date(_date));
	do {
		cout << "时间：";
		cin >> _time;
	} while (!C.set_time(_time));
	do {
		cout << "地点：";
		cin >> _location;
	} while (!C.set_location(_location));
	Cs.push_back(C);
	return true;
}

bool CA::delete_C() {
	print_CA();
	int id;
	cout << "请输入要删除的会议编号：";
	cin >> id;
	if (id <= 0 || id > Cs.size()) {
		cout << "无效的编号" << endl;
		return false;
	}
	vector<Conference>::iterator it = Cs.begin() + (id - 1);
	Cs.erase(it);
	return true;
}

bool CA::delete_Cs() {
	Cs.erase(Cs.begin(), Cs.end());
	return true;
}

//bool CA::change_sth() {
//	int id;
//	cout << "请输入要修改的会议编号：";
//	cin >> id;
//	if (id <= 0 || id > Cs.size()) {
//		cout << "无效的编号" << endl;
//		return false;
//	}
//	vector<Conference>::iterator it = Cs.begin() + (id - 1);
//	cout << "①修改会议日期    ②修改会议时间    ③修改会议地点    ④修改会议主题" << endl;
//	int n;
//	cin >> n;
//	switch (n) {
//	case 1: {
//				string _theme;
//				do {
//					cout << "新日期：";
//					cin >> _theme;
//				} while (!it->set_theme(_theme));
//				break;
//	}
//	case 2: {
//				string _time;
//				do {
//					cout << "新时间：";
//					cin >> _time;
//				} while (!it->set_time(_time));
//				break;
//	}
//	case 3: {
//				string _location;
//				do {
//					cout << "新地点：";
//					cin >> _location;
//				} while (!it->set_location(_location));
//				break;
//	}
//	case 4: {
//				string _theme;
//				do {
//					cout << "新主题：";
//					cin >> _theme;
//				} while (!it->set_theme(_theme));
//				break;
//	}
//	default:
//		cout << "无效的输入" << endl;
//		return false;
//	}
//	return true;
//}
