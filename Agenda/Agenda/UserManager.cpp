#include "UserManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <regex>
#include <sstream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::streambuf;
using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::regex;
using std::regex_match;
using std::istringstream;
using std::ostringstream;

bool UserManager::Register() {
    User new_user;
    string name, password, password_repeat;
    do {
        cout << "�����û��������û������������ֿ�ͷ��";
        cin >> name;
    } while (!new_user.set_username(name));
    cout << "�������룺";
    cin >> password;
    cout << "��������һ�����룺";
    cin >> password_repeat;
    while (password != password_repeat) {
        cout << "������������벻ͬ������������" << endl;
        cout << "�������룺";
        cin >> password;
        cout << "��������һ�����룺";
        cin >> password_repeat;
    }
    new_user.set_password(password);
    int new_ID;
	//����1000~9999���������while��䱣֤ÿ���û���ID������ͬ
    do {
        srand((unsigned)time(NULL));
        new_ID = (rand() % (9999 - 1000 + 1)) + 1000;   
    } while (find_if(users.begin(), users.end(), [new_ID](User it) {return it.get_ID() == new_ID; }) != users.end());
    cout << "ע��ɹ���";
    new_user.set_ID(new_ID);
    cout << "����IDΪ��" << new_user.get_ID() << "  ����ʹ�ø�ID����¼�˺�" << endl;
    users.push_back(new_user);
    return true;
}

User* UserManager::login() {
    string user, password;
    cout << "ID��";
    cin >> user;
    cout << "���룺";
    cin >> password;
    const regex pattern("[[:alpha:]]+\\w*");
    if (!regex_match(user, pattern)) {     //ʹ�������ж�ID�Ƿ�Ϸ�
        istringstream is(user);
        int ID;
        is >> ID;
        auto it = find_if(users.begin(), users.end(), [ID](User i) {return i.get_ID() == ID; });
        if (it == users.end()) {
            cout << "��Ч��ID������" << endl;
			return nullptr;    //��¼ʧ��ʱ���ؿ�ָ��
        }
        else {
            if (it->password != password) {
                cout << "��Ч��ID������" << endl;
				return nullptr;    //��¼ʧ��ʱ���ؿ�ָ��
            }
            else {
                cout << "��ӭ��" << it->username << endl;
                return &(*it);    //��¼�ɹ�������User����ָ��
            }
        }
    }
    else {
        cout << "��Ч��ID" << endl;
        return nullptr;    //��¼ʧ��ʱ���ؿ�ָ��
    }
}

User* UserManager::logout() {
    return nullptr;     //���û�ָ�븳Ϊ�գ���ʾ�ǳ�
}

bool UserManager::Export() {
    ofstream of;
    string file_name = "UM_users.txt";     //���������ļ�����Ϊ UM_users.txt
    of.open(file_name, std::ios::out);
    if (of.good()) {
        streambuf *oldCout = cout.rdbuf(of.rdbuf());     //��������ض��� UM_users.txt
        for (const auto u : users) {
            cout << u.get_ID() << " " << u.username << " " << u.password << endl;
            u.print_CA();
            cout << "-!@    " << endl;  //���ַ��� "-!@    " ��Ϊ�ָ������ָ�����û�
        }
        cout.rdbuf(oldCout);     //����������õ���׼����豸
        return true;
    }
    return false;    //�������ļ�����ʧ��ʱ������false
}

bool UserManager::load() {
    ifstream in("UM_users.txt");    //�򿪵����ļ�
    if (in) {
        while (!in.eof()) {
            User user;
            int ID;
            string username, password;
            in >> ID >> username >> password;
            if (!user.set_ID(ID))
                return false;
            if (!user.set_username(username))
                return false;
            if (!user.set_password(password))
                return false;
            while (!in.eof()) {    //��ѭ�����ڵ����û�����
                ostringstream os;
                streambuf *oldCout = cout.rdbuf(os.rdbuf());    //��������ض���ostringstream�����ڹ��������ַ�
                streambuf *oldCin = cin.rdbuf(in.rdbuf());     //���������ض����ļ�������
                string check;    //check������Ϊ�жϺ�ʱ�����ָ���
                cin >> check;
				if (check != "-!@" && !user.add_C())     //���ö�·��ֵ���������ָ���ʱ�����ᵼ�����
                    return false;
                cout.rdbuf(oldCout);     //����������õ���׼����豸
                cin.rdbuf(oldCin);      //�����������õ���׼�����豸
                if (check == "-!@")    //�����ָ���������ѭ����������һ�û���Ϣ���������
                    break;
            }
            users.push_back(user);
        }
        return true;
    }
    else {
        //cout << "�����û���Ϣʧ�ܣ�\n����ǵ�һ�����д˳�������Ը���ʾ��Ϣ" << endl;
		return false;		//�򿪵����ļ�ʧ��ʱ������false
    }
}
