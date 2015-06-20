#ifndef CONFERENCEARRANGEMENT_H
#define CONFERENCEARRANGEMENT_H

#include <string>
#include <vector>
#include "Conference.h"

using std::string;
using std::vector;

class CA {
private:
    vector<Conference> Cs;  //使用vector保存所有会议
public:
    void print_CA() const;   //打印所有会议
    bool add_C();   //添加会议
    bool delete_C();   //删除会议
    bool delete_Cs();   //删除所有会议
    bool change_sth();    //改变会议的主题或日期或时间或地点    注：此功能已实现，但并未使用
};

#endif
