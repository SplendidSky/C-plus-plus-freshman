#include "ConferenceArrangement.h"
#include <iostream>
#include <vector>
#include <iomanip>

#define STANDARD_WIDTH 15    // ����׼����������Ϊ15

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
		cout << "�������⣺";
		cin >> _theme;
	} while (!C.set_theme(_theme));
	do {
		cout << "���ڣ�";
		cin >> _date;
	} while (!C.set_date(_date));
	do {
		cout << "ʱ�䣺";
		cin >> _time;
	} while (!C.set_time(_time));
	do {
		cout << "�ص㣺";
		cin >> _location;
	} while (!C.set_location(_location));
	Cs.push_back(C);
	return true;
}

bool CA::delete_C() {
	print_CA();
	int id;
	cout << "������Ҫɾ���Ļ����ţ�";
	cin >> id;
	if (id <= 0 || id > Cs.size()) {
		cout << "��Ч�ı��" << endl;
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
//	cout << "������Ҫ�޸ĵĻ����ţ�";
//	cin >> id;
//	if (id <= 0 || id > Cs.size()) {
//		cout << "��Ч�ı��" << endl;
//		return false;
//	}
//	vector<Conference>::iterator it = Cs.begin() + (id - 1);
//	cout << "���޸Ļ�������    ���޸Ļ���ʱ��    ���޸Ļ���ص�    ���޸Ļ�������" << endl;
//	int n;
//	cin >> n;
//	switch (n) {
//	case 1: {
//				string _theme;
//				do {
//					cout << "�����ڣ�";
//					cin >> _theme;
//				} while (!it->set_theme(_theme));
//				break;
//	}
//	case 2: {
//				string _time;
//				do {
//					cout << "��ʱ�䣺";
//					cin >> _time;
//				} while (!it->set_time(_time));
//				break;
//	}
//	case 3: {
//				string _location;
//				do {
//					cout << "�µص㣺";
//					cin >> _location;
//				} while (!it->set_location(_location));
//				break;
//	}
//	case 4: {
//				string _theme;
//				do {
//					cout << "�����⣺";
//					cin >> _theme;
//				} while (!it->set_theme(_theme));
//				break;
//	}
//	default:
//		cout << "��Ч������" << endl;
//		return false;
//	}
//	return true;
//}
