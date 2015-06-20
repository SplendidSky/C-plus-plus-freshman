#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>

using std::vector;

class UserManager {
private:
    vector<User> users;		//����������ע���û�
public:
    static User *logout();		//�ǳ���ǰ�û�
    bool Register();     //ע���û�
    User* login();		//��¼����¼�ɹ�ʱ�����û���ָ��
    bool Export();	//���������û���Ϣ
    bool load();		//װ���û���Ϣ
};

#endif