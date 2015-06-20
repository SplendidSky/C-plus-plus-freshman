#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person() { cout << "Construct Person" << endl; }
    ~Person() { cout << "Destruct Person" << endl; }
    string name;
    int sex;
};

class Student : virtual public Person {
public:
    Student() { cout << "Construct Student" << endl; }
    ~Student() { cout << "Destruct Student" << endl; }
    string sno;
};

class Worker : virtual public Person {
public:
    Worker() { cout << "Construct Worker" << endl; }
    ~Worker() { cout << "Destruct Worker" << endl; }
    string wno;
};

class InService : virtual public Student, public virtual Worker {
public:
    InService() { cout << "Construct InService" << endl; }
    ~InService() { cout << "Destruct InService" << endl; }
};
