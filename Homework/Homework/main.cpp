#include <iostream>
#include "myclass.h"
using namespace std;
int main() {
	int a;
	cin >> a;
	Top top(a), _top;
	Left left(a, 2), _left;  //  ����a��2�ֱ�Ϊa,b��ֵ
	Right right(a, 3), _right;  //  ����a, 3�ֱ�Ϊa,c��ֵ
	Bottom bottom(a, 2, 3, 4), _bottom;  //  ����a��2��3��4�ֱ�Ϊa,b,c,d��ֵ
	cout << "Finish" << endl;
	system("pause");
}
