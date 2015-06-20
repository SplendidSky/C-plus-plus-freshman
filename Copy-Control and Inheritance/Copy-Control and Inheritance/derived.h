#ifndef __DERIVED_H__
#define __DERIVED_H__
#include "base.h"
#include <iostream>
class Derived : public Base {
public:
	Derived() : size(0), data(NULL) {}  // Default Constructor

	/* Copy from an array */
	Derived(const int * arr, int _size, int _value = 0);  // Constructor
	Derived(const Derived&);  // Copy Constructor
	Derived& operator=(const Derived&);

	friend std::ostream& operator<<(std::ostream&, const Derived&);
	~Derived();  // destructor

private:
	int* data;  // stores datas
	unsigned size;  // size of data
};

#endif
