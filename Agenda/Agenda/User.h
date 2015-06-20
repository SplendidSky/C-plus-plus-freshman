#ifndef USER_H
#define USER_H

#include "ConferenceArrangement.h"
#include <string>
using std::string;

class User {
private:
    CA ca;
    int ID;   //�û�Ψһ��ʾ��
    string username;    //�û��������������ֿ�ͷ
    string password;
public:
    friend class UserManager;    //����UserManagerΪ��Ԫ�࣬�����User���ݳ�Ա�Ĳ���
    bool set_password(string new_password);    //�������룬Ϊ����ʹ��δ�����밲ȫ�����
    bool set_username(string new_username);   //�����û������û������������ֿ�ͷ
    bool set_ID(int id);   //�����û�ID��Ϊ�û�Ψһ��ʾ��
    int get_ID() const;    //�����û�ID
    bool add_C();    //��ӻ���
    bool delete_C();   //ɾ������
    bool delete_CA();   //ɾ�����л���
    bool Export() const;    //�������鰲��
    void print_CA() const;   //��ӡ���鰲��

	string get_username() const;   //�����û���
};

#endif
