#include "БъЭЗ.h"
#include <string.h>
#include <iostream>

string::string(){};
string::string(const char *c) {
	int size = strlen(c) + 1;
	str = new char[size];
	strcpy_s(str, size, c);
}
string::~string() {
	delete[] str;
}
int string::length() const{
	return strlen(str);
}
string string::operator=(char *c) {
	return string(c);
}
string string::operator=(const string &s) {
	return string(s.str);
}
char &string::operator[](const int &index) const {
	if (index >= 0)
		return str[index];
	else
		return str[length() + index];
}
string const string::operator+(const string &s) const{
	int size = strlen(this->str) + strlen(s.str) + 1;
	char *temp = new char[size];
	strcpy_s(temp, size, str);
	strcat_s(temp, size, s.str);
	return string(temp);
}
string const string::operator+(const char *c) const{
	int size = strlen(this->str) + strlen(c) + 1;
	char *temp = new char[size];
	strcpy_s(temp, size, str);
	strcat_s(temp, size, c);
	return string(temp);
}
istream &operator>>(istream &is, string &s) {
	s.str = new char[stdin->_bufsiz];
	return is >> s.str;
}
ostream &operator<<(ostream &os, const string &s) {
	return os << s.str;
}
