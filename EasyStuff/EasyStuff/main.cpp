#include <iostream>
#include "ExpandedVector.h"

int main() {
	ExpandedVector v;
	int size;
	std::cin >> size;
	int val;
	for (int i = 0; i < size; i++) {
		std::cin >> val;
		v.push_back(val);
	}
	v.my_reverse();
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	return 0;
}
