#include "User.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <iomanip>

#define STANDARD_WIDTH 15    // 将标准输出宽度设置为15

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
	const regex pattern("[[:alpha:]]+\\w*");    //使用正则表达式保证username不以数字开头
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
	string file_name = this->username + ".txt";     //导出会议时，将文件命名为当前用户的用户名
	of.open(file_name, std::ios::out);
	if (of.good()) {
		streambuf *oldCout = cout.rdbuf(of.rdbuf());    //重定向输出流
		cout.setf(std::ios::left);
		cout << setw(STANDARD_WIDTH);
		cout << "会议ID";
		cout << setw(STANDARD_WIDTH);
		cout << "主题";
		cout << setw(STANDARD_WIDTH);
		cout << "日期";
		cout << setw(STANDARD_WIDTH);
		cout << "时间";
		cout << setw(STANDARD_WIDTH);
		cout << "地点";
		cout << endl;
		ca.print_CA();
		cout.rdbuf(oldCout);    //使输出流重新流向标准输出设备
		return true;
	}
	return false;     //未能创建导出文件时，返回false
}

void User::print_CA() const {
	ca.print_CA();
}

string User::get_username() const {
	return username;
}