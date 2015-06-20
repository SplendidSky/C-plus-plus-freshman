#include <iostream>
#include <cstdio>
#include "header.h"
#pragma warning(disable : 4996)
using namespace std;
int main() {
	int n, dec;
	char hexString[5][10];
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", hexString[i]);
	try {
		for (int i = 0; i < n; i++)
			cout << parseHex(hexString[i]) << endl;
	}
	catch (runtime_error ex) {
		cout << ex.what() << endl;
	}
	system("pause");
	return 0;
}
