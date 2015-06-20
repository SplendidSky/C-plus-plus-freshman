#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>

using std::vector;

class UserManager {
private:
    vector<User> users;		//保存所有已注册用户
public:
    static User *logout();		//登出当前用户
    bool Register();     //注册用户
    User* login();		//登录，登录成功时返回用户的指针
    bool Export();	//导出所有用户信息
    bool load();		//装载用户信息
};

#endif