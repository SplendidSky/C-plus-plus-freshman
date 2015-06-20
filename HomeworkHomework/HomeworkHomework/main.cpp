#include <iostream>
#include "source.cpp"
using namespace std;

int main() {
	InService is;

	Person* p = &is;
	Student* s = &is;
	Worker* w = &is;

	is.name = "name";
	is.sex = 0;
	is.sno = "10390000";
	is.wno = "10990000";

	cout << p->name << endl;
	cout << p->sex << endl;
	cout << s->name << endl;
	cout << s->sex << endl;
	cout << s->sno << endl;
	cout << w->name << endl;
	cout << w->sex << endl;
	cout << w->wno << endl;
	return 0;
}