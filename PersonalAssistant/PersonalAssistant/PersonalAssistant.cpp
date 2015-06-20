#include "PersonalAssistant.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

//格式化时输出的宽度
#define STANDARD_WIDTH 15

using std::cout;
using std::cin;
using std::endl;
using std::for_each;


void PersonalAssistant::PersonalAssistant::listEvents() const {
	int i = 1;
	for (auto const &e : events) {
		cout.setf(std::ios::left);
		cout.width(STANDARD_WIDTH);
		cout << i++;
		cout << e << endl;
	}
	cout << endl;
}

void PersonalAssistant::PersonalAssistant::listTasks() const {
	int i = 1;
	for (auto const &t : tasks) {
		cout.setf(std::ios::left);
		cout.width(STANDARD_WIDTH);
		cout << i++;
		cout << t << endl;
	}
	cout << endl;
}

void PersonalAssistant::PersonalAssistant::listTodos() const {
	//列出所有事件
	if (events.size()) {
		cout << endl;
		cout.setf(std::ios::left);
		cout.width(STANDARD_WIDTH);
		cout << "事件编号：";
		cout.width(STANDARD_WIDTH);
		cout << "事件名称：";
		cout.width(STANDARD_WIDTH);
		cout << "时间：";
		cout.width(STANDARD_WIDTH);
		cout << "地点：";
		cout.width(STANDARD_WIDTH);
		cout << "备注：" << endl;
		listEvents();
	}

	//列出所有任务
	if (tasks.size()) {
		cout << endl;
		cout.setf(std::ios::left);
		cout.width(STANDARD_WIDTH);
		cout << "任务编号：";
		cout.width(STANDARD_WIDTH);
		cout << "任务名称：";
		cout.width(STANDARD_WIDTH);
		cout << "DDL：";
		cout.width(STANDARD_WIDTH);
		cout << "备注：" << endl;
		listTasks();
	}
}

void PersonalAssistant::PersonalAssistant::addTodo() {
	cout << "添加：①事件   ②任务" << endl;
	string n;
	cin >> n;
	if (n == "1") {
		Event::event e;
		string name, time, location, notes;
		do {
			cout << "事件名称：" << endl;
			cin >> name;
		} while (!e.setEvent(name));
		do {
			cout << "时间：" << endl;
			cin >> time;
		} while (!e.setTime(time));
		do {
			cout << "地点：" << endl;
			cin >> location;
		} while (!e.setLocation(location));
		do {
			cout << "备注：" << endl;
			cin >> notes;
		} while (!e.setNotes(notes));
		events.push_back(e);
		cout << "事件添加成功！" << endl;
		listTodos();
	}
	else if (n == "2") {
		Task::task t;
		string name, DDL, notes;
		do {
			cout << "任务名称：" << endl;
			cin >> name;
		} while (!t.setTask(name));
		do {
			cout << "DDL：" << endl;
			cin >> DDL;
		} while (!t.setDDL(DDL));
		do {
			cout << "备注：" << endl;
			cin >> notes;
		} while (!t.setNotes(notes));
		tasks.push_back(t);
		cout << "任务添加成功！" << endl;
		listTodos();
	}

	//输入无效时重新调用此函数
	else
		addTodo();
}

bool PersonalAssistant::PersonalAssistant::deleteDone() {
	listTodos();
	cout << "①删除事件  ②删除任务\t输入任意其它字符放弃删除" << endl;
	string n;
	cin >> n;
	if (n == "1") {
		if (events.size() == 0) {
			cout << "当前没有待办事件" << endl;
			cout << endl;
			return false;
		}
		cout << "输入事件编号：";
		string i_;
		cin >> i_;
		int i = std::atoi(i_.c_str());
		if (i < events.size() + 2 && i > 0) {
			events.erase(events.begin() + i - 1);
			cout << "命令成功完成！" << endl;
			cout << endl;
			return true;
		}
		else {
			cout << "*****命令未成功完成，请确保输入合法*****" << endl;
			cout << endl;
			return false;
		}
	}
	else if (n == "2") {
		if (tasks.size() == 0) {
			cout << "当前没有未完成任务" << endl;
			cout << endl;
			return false;
		}
		cout << "输入任务编号：";
		string i_;
		cin >> i_;
		int i = std::atoi(i_.c_str());
		if (i < tasks.size() + 2 && i > 0) {
			tasks.erase(tasks.begin() + i - 1);
			cout << "命令成功完成！" << endl;
			cout << endl;
			return true;
		}
		else {
			cout << "*****命令未成功完成，请确保输入合法*****" << endl;
			cout << endl;
			return false;
		}
	}
}
