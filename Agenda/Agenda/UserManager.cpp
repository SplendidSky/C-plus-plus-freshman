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
        cout << "设置用户名：（用户名不能以数字开头）";
        cin >> name;
    } while (!new_user.set_username(name));
    cout << "设置密码：";
    cin >> password;
    cout << "请再输入一次密码：";
    cin >> password_repeat;
    while (password != password_repeat) {
        cout << "两次输入的密码不同！请重新输入" << endl;
        cout << "设置密码：";
        cin >> password;
        cout << "请再输入一次密码：";
        cin >> password_repeat;
    }
    new_user.set_password(password);
    int new_ID;
	//生成1000~9999的随机数，while语句保证每个用户的ID都不相同
    do {
        srand((unsigned)time(NULL));
        new_ID = (rand() % (9999 - 1000 + 1)) + 1000;   
    } while (find_if(users.begin(), users.end(), [new_ID](User it) {return it.get_ID() == new_ID; }) != users.end());
    cout << "注册成功！";
    new_user.set_ID(new_ID);
    cout << "您的ID为：" << new_user.get_ID() << "  您将使用该ID来登录账号" << endl;
    users.push_back(new_user);
    return true;
}

User* UserManager::login() {
    string user, password;
    cout << "ID：";
    cin >> user;
    cout << "密码：";
    cin >> password;
    const regex pattern("[[:alpha:]]+\\w*");
    if (!regex_match(user, pattern)) {     //使用正则判断ID是否合法
        istringstream is(user);
        int ID;
        is >> ID;
        auto it = find_if(users.begin(), users.end(), [ID](User i) {return i.get_ID() == ID; });
        if (it == users.end()) {
            cout << "无效的ID或密码" << endl;
			return nullptr;    //登录失败时返回空指针
        }
        else {
            if (it->password != password) {
                cout << "无效的ID或密码" << endl;
				return nullptr;    //登录失败时返回空指针
            }
            else {
                cout << "欢迎，" << it->username << endl;
                return &(*it);    //登录成功！返回User类型指针
            }
        }
    }
    else {
        cout << "无效的ID" << endl;
        return nullptr;    //登录失败时返回空指针
    }
}

User* UserManager::logout() {
    return nullptr;     //将用户指针赋为空，表示登出
}

bool UserManager::Export() {
    ofstream of;
    string file_name = "UM_users.txt";     //将导出的文件命名为 UM_users.txt
    of.open(file_name, std::ios::out);
    if (of.good()) {
        streambuf *oldCout = cout.rdbuf(of.rdbuf());     //将输出流重定向到 UM_users.txt
        for (const auto u : users) {
            cout << u.get_ID() << " " << u.username << " " << u.password << endl;
            u.print_CA();
            cout << "-!@    " << endl;  //以字符串 "-!@    " 作为分隔符，分割各个用户
        }
        cout.rdbuf(oldCout);     //将输出流重置到标准输出设备
        return true;
    }
    return false;    //当导出文件创建失败时，返回false
}

bool UserManager::load() {
    ifstream in("UM_users.txt");    //打开导入文件
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
            while (!in.eof()) {    //此循环用于导入用户会议
                ostringstream os;
                streambuf *oldCout = cout.rdbuf(os.rdbuf());    //将输出流重定向到ostringstream，用于过滤无用字符
                streambuf *oldCin = cin.rdbuf(in.rdbuf());     //将输入流重定向到文件输入流
                string check;    //check的作用为判断何时遇到分隔符
                cin >> check;
				if (check != "-!@" && !user.add_C())     //利用短路求值，当遇到分隔符时将不会导入会议
                    return false;
                cout.rdbuf(oldCout);     //将输出流重置到标准输出设备
                cin.rdbuf(oldCin);      //将输入流重置到标准输入设备
                if (check == "-!@")    //遇到分隔符跳出此循环，导入下一用户信息或结束导入
                    break;
            }
            users.push_back(user);
        }
        return true;
    }
    else {
        //cout << "导入用户信息失败！\n如果是第一次运行此程序，请忽略该提示信息" << endl;
		return false;		//打开导入文件失败时，返回false
    }
}
