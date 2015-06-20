#include <iostream>
#include "base.h"
#include "derived.h"
using namespace std;

std::ostream& operator<<(std::ostream& os, const Derived& d) {
	os << "Base Value: " << d.getValue() << std::endl;
	os << "Derived Datas: ";
	if (d.size > 0) {
		os << d.data[0];
		for (unsigned i = 1; i < d.size; i++)
			os << " " << d.data[i];
	}
	return os;
}

int main() {
	int a[10];
	int b[10];
	int cnt1, cnt2, value;
	cin >> cnt1 >> cnt2;
	for (int i = 0; i < cnt1; i++)
		cin >> a[i];
	for (int i = 0; i < cnt2; i++)
		cin >> b[i];
	cin >> value;
	Derived d1(a, cnt1, value);
	cin >> value;
	Derived d2(b, cnt2, value);
	cout << d1 << endl;
	cout << d2 << endl;

	Derived d3(d1);
	cout << d3 << endl;
	d3 = d2;
	d3 = d3;
	cout << d3 << endl;

	system("pause");

	return 0;
}
