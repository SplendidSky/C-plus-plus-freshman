#include "PersonalAssistant.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

//��ʽ��ʱ����Ŀ��
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
	//�г������¼�
	if (events.size()) {
		cout << endl;
		cout.setf(std::ios::left);
		cout.width(STANDARD_WIDTH);
		cout << "�¼���ţ�";
		cout.width(STANDARD_WIDTH);
		cout << "�¼����ƣ�";
		cout.width(STANDARD_WIDTH);
		cout << "ʱ�䣺";
		cout.width(STANDARD_WIDTH);
		cout << "�ص㣺";
		cout.width(STANDARD_WIDTH);
		cout << "��ע��" << endl;
		listEvents();
	}

	//�г���������
	if (tasks.size()) {
		cout << endl;
		cout.setf(std::ios::left);
		cout.width(STANDARD_WIDTH);
		cout << "�����ţ�";
		cout.width(STANDARD_WIDTH);
		cout << "�������ƣ�";
		cout.width(STANDARD_WIDTH);
		cout << "DDL��";
		cout.width(STANDARD_WIDTH);
		cout << "��ע��" << endl;
		listTasks();
	}
}

void PersonalAssistant::PersonalAssistant::addTodo() {
	cout << "��ӣ����¼�   ������" << endl;
	string n;
	cin >> n;
	if (n == "1") {
		Event::event e;
		string name, time, location, notes;
		do {
			cout << "�¼����ƣ�" << endl;
			cin >> name;
		} while (!e.setEvent(name));
		do {
			cout << "ʱ�䣺" << endl;
			cin >> time;
		} while (!e.setTime(time));
		do {
			cout << "�ص㣺" << endl;
			cin >> location;
		} while (!e.setLocation(location));
		do {
			cout << "��ע��" << endl;
			cin >> notes;
		} while (!e.setNotes(notes));
		events.push_back(e);
		cout << "�¼���ӳɹ���" << endl;
		listTodos();
	}
	else if (n == "2") {
		Task::task t;
		string name, DDL, notes;
		do {
			cout << "�������ƣ�" << endl;
			cin >> name;
		} while (!t.setTask(name));
		do {
			cout << "DDL��" << endl;
			cin >> DDL;
		} while (!t.setDDL(DDL));
		do {
			cout << "��ע��" << endl;
			cin >> notes;
		} while (!t.setNotes(notes));
		tasks.push_back(t);
		cout << "������ӳɹ���" << endl;
		listTodos();
	}

	//������Чʱ���µ��ô˺���
	else
		addTodo();
}

bool PersonalAssistant::PersonalAssistant::deleteDone() {
	listTodos();
	cout << "��ɾ���¼�  ��ɾ������\t�������������ַ�����ɾ��" << endl;
	string n;
	cin >> n;
	if (n == "1") {
		if (events.size() == 0) {
			cout << "��ǰû�д����¼�" << endl;
			cout << endl;
			return false;
		}
		cout << "�����¼���ţ�";
		string i_;
		cin >> i_;
		int i = std::atoi(i_.c_str());
		if (i < events.size() + 2 && i > 0) {
			events.erase(events.begin() + i - 1);
			cout << "����ɹ���ɣ�" << endl;
			cout << endl;
			return true;
		}
		else {
			cout << "*****����δ�ɹ���ɣ���ȷ������Ϸ�*****" << endl;
			cout << endl;
			return false;
		}
	}
	else if (n == "2") {
		if (tasks.size() == 0) {
			cout << "��ǰû��δ�������" << endl;
			cout << endl;
			return false;
		}
		cout << "���������ţ�";
		string i_;
		cin >> i_;
		int i = std::atoi(i_.c_str());
		if (i < tasks.size() + 2 && i > 0) {
			tasks.erase(tasks.begin() + i - 1);
			cout << "����ɹ���ɣ�" << endl;
			cout << endl;
			return true;
		}
		else {
			cout << "*****����δ�ɹ���ɣ���ȷ������Ϸ�*****" << endl;
			cout << endl;
			return false;
		}
	}
}
