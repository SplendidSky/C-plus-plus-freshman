#
#include "PersonalAssistant.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

int main() {
	cout << "欢迎使用PersonalAssistant\t\t\tby : SplendidSky" << endl << endl;
	PersonalAssistant::PersonalAssistant PA;
	PA.addTodo();
	while (1) {
		cout << "①添加事件或任务  ②移除已完成事件或任务  ③导出数据" << endl;
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
			cout << "成功导出数据至output.txt！" << endl;
		}
		else {
			cout << "无效的输入" << endl;
		}
	}
	system("pause");
}