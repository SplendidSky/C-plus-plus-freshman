#include <iostream>
#include "singleton.h"
void check_delete(bool result) {
	if (result)
		std::cout << "Delete Successfully!" << std::endl;
	else
		std::cout << "Delete Failed!" << std::endl;
}

int main() {
	int value;
	int cnt;  // count to print
	std::cin >> value >> cnt;
	Singleton* single[2] = { NULL, NULL };
	single[0] = Singleton::GetInstance();
	single[1] = Singleton::GetInstance();

	single[0]->SetValue(value);
	for (int i = 0; i < cnt; i++)
		std::cout << single[i]->GetValue() << std::endl;

	std::cin >> value >> cnt;
	single[1]->SetValue(value);
	for (int i = 0; i < cnt; i++)
		std::cout << single[i]->GetValue() << std::endl;

	bool del;
	std::cin >> del;
	if (del)
		check_delete(single[0]->DeleteInstance());
	check_delete(single[1]->DeleteInstance());

	return 0;
}
