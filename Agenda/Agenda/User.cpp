#include "User.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <iomanip>

#define STANDARD_WIDTH 15    // ����׼����������Ϊ15

using std::setw;
using std::cout;
using std::cin;
using std::endl;
using std::regex;
using std::regex_match;
using std::streambuf;
using std::ofstream;
using std::ifstream;

bool User::set_password(string new_password) {
	password = new_password;
	return true;
}

bool User::set_username(string new_username) {
	const regex pattern("[[:alpha:]]+\\w*");    //ʹ��������ʽ��֤username�������ֿ�ͷ
	username = new_username;
	return regex_match(new_username, pattern);
}

bool User::add_C() {
	return ca.add_C();
}

bool User::delete_C() {
	return ca.delete_C();
}

bool User::delete_CA() {
	ca.delete_Cs();
	return true;
}

bool User::set_ID(int id) {
	ID = id;
	return true;
}

int User::get_ID() const {
	return ID;
}

bool User::Export() const {
	ofstream of;
	string file_name = this->username + ".txt";     //��������ʱ�����ļ�����Ϊ��ǰ�û����û���
	of.open(file_name, std::ios::out);
	if (of.good()) {
		streambuf *oldCout = cout.rdbuf(of.rdbuf());    //�ض��������
		cout.setf(std::ios::left);
		cout << setw(STANDARD_WIDTH);
		cout << "����ID";
		cout << setw(STANDARD_WIDTH);
		cout << "����";
		cout << setw(STANDARD_WIDTH);
		cout << "����";
		cout << setw(STANDARD_WIDTH);
		cout << "ʱ��";
		cout << setw(STANDARD_WIDTH);
		cout << "�ص�";
		cout << endl;
		ca.print_CA();
		cout.rdbuf(oldCout);    //ʹ��������������׼����豸
		return true;
	}
	return false;     //δ�ܴ��������ļ�ʱ������false
}

void User::print_CA() const {
	ca.print_CA();
}

string User::get_username() const {
	return username;
}