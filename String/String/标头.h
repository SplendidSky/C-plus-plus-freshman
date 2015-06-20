//#ifndef "БъЭЗ.h"
//#define

#include <iostream>
using std::istream;
using std::ostream;

class string {
public:
	string(const char *c);
	string();
	~string();
	int length()const;
	string operator=(char *c);
	string operator=(const string &s);
	string const operator+(const string &str)const;
	string const operator+(const char *c)const;
	char &operator[](const int &index) const;
	friend istream &operator>>(istream &is, string &s);
	friend ostream &operator<<(ostream &os, const string &s);

private:
	char *str;
};

//#endif