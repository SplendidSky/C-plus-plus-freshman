#
#include "PersonalAssistant.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

int main() {
	cout << "��ӭʹ��PersonalAssistant\t\t\tby : SplendidSky" << endl << endl;
	PersonalAssistant::PersonalAssistant PA;
	PA.addTodo();
	while (1) {
		cout << "������¼�������  ���Ƴ�������¼�������  �۵�������" << endl;
		string n;
		cin >> n;
		if (n == "1") {
			PA.addTodo();
		}
		else if (n == "2") {
			PA.deleteDone();
		}
		else if (n == "3") {
			ofstream of("output.txt");
			std::streambuf *oldCout = cout.rdbuf(of.rdbuf());
			PA.listTodos();
			cout.rdbuf(oldCout);
			cout << "�ɹ�����������output.txt��" << endl;
		}
		else {
			cout << "��Ч������" << endl;
		}
	}
	system("pause");
}