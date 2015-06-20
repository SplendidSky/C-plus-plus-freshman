#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

using namespace std;

enum Type {
    CAT,
    DOG
};

class Animal {
public:
    Animal(){}
    Animal(std::string _name, int _age) : name(_name), age(_age), exist(true) {}
    virtual void Shout() const = 0;
    virtual Type getType() const = 0;
    std::string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
	bool exist;
private:
    std::string name;
    int age;
};

class Cat : public Animal {
public:
    Cat(){}
    Cat(string _name, int age) : Animal(_name, age) {}
    virtual void Shout() const { cout << getName() << ": meow~~" << endl; }
    Type getType() const { return Type::CAT; }
};
class Dog : public Animal {
public:
    Dog(){}
    Dog(string _name, int age) : Animal(_name, age) {}
    virtual void Shout() const { cout << getName() << ": bark!!" << endl; }
    Type getType() const { return Type::DOG; }
};
#endif
