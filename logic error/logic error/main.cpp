#include <iostream>
#include "check.h"
using namespace std;

int main() {
	int n;
	int arr[10];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	try {
		for (int i = 0; i < n; i++)
			check_negative(arr[i]);
	}
	catch (logic_error ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
