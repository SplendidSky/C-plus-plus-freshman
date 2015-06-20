#include <iostream>
#include "array.h"

#define $(start, end, step) .slice(start, end, step)

using namespace std;

void print(int & value) {
	cout << value << " ";
}

void print(double & value) {
	cout << value << " ";
}

void add(int & value) {
	value++;
}

void sub(int & value) {
	value--;
}

void timesTen(int & value) {
	value *= 10;
}
int main(void) {
	int length;
	cin >> length;
	Array<int> test(length), copy;
	for (int i = 0; i < length; i++) {
		cin >> test[i];
	}
	copy = test;
	test = (copy)$(0, length - 1, 1);
	test.traverse(print);
	cout << endl;
	test.traverse(add);
	test.traverse(print);
	cout << endl;
	test = (copy)$(0, length / 2, -1);
	test.traverse(print);
	cout << endl;
	test.traverse(sub);
	test.traverse(print);
	cout << endl;
	test = (copy)$(0, length - 1, 2);
	test.traverse(print);
	cout << endl;
	test.traverse(timesTen);
	test.traverse(print);
	cout << endl;

	cin >> length;
	Array<double> test2(length);
	for (int i = 0; i < length; i++) {
		cin >> test2[i];
	}
	test2.traverse(print);
	cout << endl;
	return 0;
}
