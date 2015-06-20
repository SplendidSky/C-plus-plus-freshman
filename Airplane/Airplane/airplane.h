#include <iostream>
#include <string>

using namespace std;

class Airplane {
public:
    virtual void fly(const string& dest) = 0;
protected:
    void defaultFly(const string& dest);
};

class ModelA : public Airplane {
public:
    void fly(const std::string &dest) override
    { cout << "The airplane flies straightly to airport " << dest << "." << endl; }
};

using ModelB = ModelA;

class ModelC : public Airplane {
public:
    void fly(const std::string &dest) override
    { cout << "The airplane flies in a semi-circle track to airport " << dest << "." << endl; }
};
