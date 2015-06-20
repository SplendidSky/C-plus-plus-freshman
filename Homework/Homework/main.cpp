#include <iostream>
#include "myclass.h"
using namespace std;
int main() {
	int a;
	cin >> a;
	Top top(a), _top;
	Left left(a, 2), _left;  //  其中a，2分别为a,b的值
	Right right(a, 3), _right;  //  其中a, 3分别为a,c的值
	Bottom bottom(a, 2, 3, 4), _bottom;  //  其中a，2，3，4分别为a,b,c,d的值
	cout << "Finish" << endl;
	system("pause");
}
