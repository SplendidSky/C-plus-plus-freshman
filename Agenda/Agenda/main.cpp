#include "Conference.h"
#include "ConferenceArrangement.h"
#include "User.h"
#include "UserManager.h"
#include <iostream>
#include <string>
#include <iomanip>

using std::setw;
using std::string;
using std::cout;
using std::endl;
using std::cin;

#define STANDARD_WIDTH 15    // 将标准输出宽度设置为15

int main() {
    UserManager UM;
    UM.load();
	cout << "欢迎使用Agenda\t\tby : SplendidSky" << endl << endl;
    while (1) {
        cout << "①登录 ②注册 ③退出" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") {
            User *user = UM.login();
            while (user) {
                cout << "①查看所有会议    ②添加会议    ③删除会议    ④删除所有会议    ⑤导出会议    ⑥注销" << endl;
                string user_choice;
                cin >> user_choice;
                if (user_choice == "1") {
                    cout.setf(std::ios::left);
                    cout << setw(STANDARD_WIDTH);
                    cout << "会议ID";
                    cout << setw(STANDARD_WIDTH);
                    cout << "主题";
                    cout << setw(STANDARD_WIDTH);
                    cout << "日期";
                    cout << setw(STANDARD_WIDTH);
                    cout << "时间";
                    cout << setw(STANDARD_WIDTH);
                    cout << "地点";
                    cout << endl;
                    user->print_CA();
                }
                else if (user_choice == "2") {
                    if (user->add_C()) {
                        cout << "添加成功！" << endl;
						UM.Export();
                    }
                }
                else if (user_choice == "3") {
                    if (user->delete_C()) {
                        cout << "删除成功！" << endl;
						UM.Export();
                    }
                }
                else if (user_choice == "4") {
                    cout << "此操作将清空当前用户所有会议记录，键入Y/y继续操作" << endl;
                    string check;
                    cin >> check;
                    if (check == "Y" || check == "y") {
                        if (user->delete_CA()) {
                            cout << "成功清除当前用户所有会议记录！" << endl;
							UM.Export();
                        }
                    }
                }
                else if (user_choice == "5") {
                    if (user->Export()) {
                        cout << "导出成功！" << endl;
                    }
                    else {
                        cout << "导出失败！" << endl;
                    }
                }
                else if (user_choice == "6") {
                    user = UserManager::logout();
                }
                else continue;
            }
            continue;
        }
        else if (choice == "2") {
            UM.Register();
        }
        else if (choice == "3") {
            break;
        }
        else continue;
    }
    UM.Export();
    system("pause");
}
