#include <iostream>
#include <stdexcept>

void multi_throw(int i) {
	std::cout << "Input: " << i << std::endl;
	if (i <= 0) throw std::logic_error("non-positive");
	if (i <= 1) throw i;
	if (i <= 5) throw std::runtime_error("run error");
	if (i >= 9) throw std::out_of_range("too big");
}
