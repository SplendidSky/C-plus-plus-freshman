#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <string>

using std::string;

class Conference {
private:
    string date;    //��������
    string time;    //����ʱ��
    string location;   //����ص�
    string theme;    //��������
public:
    Conference() {}
    bool set_time(string _time);    //���û���ʱ��
    bool set_date(string _date);    //���û�������
    bool set_location(string _location);    //���û���ص�
    bool set_theme(string _theme);    //���û�������

    string get_time() const;    //���ػ���ʱ��
    string get_date() const;    //���ػ�������
	string get_location() const;    //���ػ���ص�
	string get_theme() const;    //���ػ�������

    bool print_C() const;		//��ӡ����
};

#endif