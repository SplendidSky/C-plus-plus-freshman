#ifndef CONFERENCEARRANGEMENT_H
#define CONFERENCEARRANGEMENT_H

#include <string>
#include <vector>
#include "Conference.h"

using std::string;
using std::vector;

class CA {
private:
    vector<Conference> Cs;  //ʹ��vector�������л���
public:
    void print_CA() const;   //��ӡ���л���
    bool add_C();   //��ӻ���
    bool delete_C();   //ɾ������
    bool delete_Cs();   //ɾ�����л���
    bool change_sth();    //�ı�������������ڻ�ʱ���ص�    ע���˹�����ʵ�֣�����δʹ��
};

#endif
