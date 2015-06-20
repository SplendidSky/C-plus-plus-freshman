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

#define STANDARD_WIDTH 15    // ����׼����������Ϊ15

int main() {
    UserManager UM;
    UM.load();
	cout << "��ӭʹ��Agenda\t\tby : SplendidSky" << endl << endl;
    while (1) {
        cout << "�ٵ�¼ ��ע�� ���˳�" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") {
            User *user = UM.login();
            while (user) {
                cout << "�ٲ鿴���л���    ����ӻ���    ��ɾ������    ��ɾ�����л���    �ݵ�������    ��ע��" << endl;
                string user_choice;
                cin >> user_choice;
                if (user_choice == "1") {
                    cout.setf(std::ios::left);
                    cout << setw(STANDARD_WIDTH);
                    cout << "����ID";
                    cout << setw(STANDARD_WIDTH);
                    cout << "����";
                    cout << setw(STANDARD_WIDTH);
                    cout << "����";
                    cout << setw(STANDARD_WIDTH);
                    cout << "ʱ��";
                    cout << setw(STANDARD_WIDTH);
                    cout << "�ص�";
                    cout << endl;
                    user->print_CA();
                }
                else if (user_choice == "2") {
                    if (user->add_C()) {
                        cout << "��ӳɹ���" << endl;
						UM.Export();
                    }
                }
                else if (user_choice == "3") {
                    if (user->delete_C()) {
                        cout << "ɾ���ɹ���" << endl;
						UM.Export();
                    }
                }
                else if (user_choice == "4") {
                    cout << "�˲�������յ�ǰ�û����л����¼������Y/y��������" << endl;
                    string check;
                    cin >> check;
                    if (check == "Y" || check == "y") {
                        if (user->delete_CA()) {
                            cout << "�ɹ������ǰ�û����л����¼��" << endl;
							UM.Export();
                        }
                    }
                }
                else if (user_choice == "5") {
                    if (user->Export()) {
                        cout << "�����ɹ���" << endl;
                    }
                    else {
                        cout << "����ʧ�ܣ�" << endl;
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
