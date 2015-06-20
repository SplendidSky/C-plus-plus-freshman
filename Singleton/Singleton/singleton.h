#ifndef __SINGLETON_H_
#define __SINGLETON_H_

#include <iostream>

/* disallow copy constructor and assignment operator */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&)

class Singleton {
public:
	/*
	* get the unique instance
	*/
	static Singleton* GetInstance();

	/*
	* delete the instance
	* if the instance not exist, return false
	*/
	static bool DeleteInstance();
	void SetValue(int value);
	int GetValue();

private:
	int value_;  // default 0
	~Singleton() {}
	Singleton();
	static Singleton* instance_;
	DISALLOW_COPY_AND_ASSIGN(Singleton);
};

#endif