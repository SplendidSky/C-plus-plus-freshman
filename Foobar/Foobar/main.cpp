#include "Foobar.h"

int main() {
	Foobar<int> foo0(6);
	std::cout << foo0 << std::endl;
	Foobar<double> foo1(6.666);
	std::cout << foo1 << std::endl;
	Foobar<char> foo2('c');
	std::cout << foo2 << std::endl;
	return 0;
}