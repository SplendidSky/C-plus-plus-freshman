#include "animal.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zoo {
public:
	Zoo() : catCount(0), dogCount(0) {}
	void addAnimal(Animal *a);
	int getCatCount();
	int getDogCount();
	void deleteAnimalByName(string name);
	void deleteAnimalByAge(int age);
	void print();
private:
	int catCount;
	int dogCount;
	vector<Animal *> animal;
};

void Zoo::addAnimal(Animal *a) {
	animal.push_back(a);
	if (a->getType() == CAT)
		catCount++;
	else
		dogCount++;
}
int Zoo::getCatCount() { return catCount; }
int Zoo::getDogCount() { return dogCount; }
void Zoo::deleteAnimalByName(string name) {
	for (vector<Animal *>::iterator i = animal.begin();
		i != animal.end(); i++) {
		if ((*i)->getName() == name && (*i)->exist == true) {
			if ((*i)->getType() == CAT)
				catCount--;
			else
				dogCount--;
			(*i)->exist = false;
		}
	}
}
void Zoo::deleteAnimalByAge(int age) {
	for (vector<Animal *>::iterator i = animal.begin();
		i != animal.end(); i++) {
		if ((*i)->getAge() == age && (*i)->exist == true) {
			if ((*i)->getType() == CAT)
				catCount--;
			else
				dogCount--;
			(*i)->exist = false;
		}
	}
}
void Zoo::print() {
	for (vector<Animal *>::iterator i = animal.begin(); i != animal.end(); i++)
		(*i)->Shout();
}