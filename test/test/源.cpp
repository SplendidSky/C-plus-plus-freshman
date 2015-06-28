#include <iostream>

using namespace std;

void foo(const int &i) {
	cout << i << "\t" << &i << endl;
}
int main() {
	double d = 2.01;
	foo(d);
	cout << d << "\t" << &d <<endl;
	system("pause");
}