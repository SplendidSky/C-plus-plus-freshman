#ifndef USER_H
#define USER_H

#include "ConferenceArrangement.h"
#include <string>
using std::string;

class User {
private:
    CA ca;
    int ID;   //用户唯一标示符
    string username;    //用户名，不能以数字开头
    string password;
public:
    friend class UserManager;    //设置UserManager为友元类，方便对User数据成员的操作
    bool set_password(string new_password);    //设置密码，为方便使用未对密码安全做检测
    bool set_username(string new_username);   //设置用户名，用户名不能以数字开头
    bool set_ID(int id);   //设置用户ID作为用户唯一标示符
    int get_ID() const;    //返回用户ID
    bool add_C();    //添加会议
    bool delete_C();   //删除会议
    bool delete_CA();   //删除所有会议
    bool Export() const;    //导出会议安排
    void print_CA() const;   //打印会议安排

	string get_username() const;   //返回用户名
};

#endif
