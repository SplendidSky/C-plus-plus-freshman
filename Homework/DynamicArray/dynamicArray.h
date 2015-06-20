#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <vector>
#include <ostream>

#define nullptr NULL

class dynamic_array {
private:
	static const int _DEFAULT_SIZE = 10;
	unsigned _size;     // Current size
	int * _data;    // An array storing data
	void cpy(int *, const int *, const unsigned &);
	// A private method that copy data from one array to another.
	// The third argument stands for the size.
	void grow();
	// If the current array don't have enough space, use this method
	// to double the size.
	// Don't forget to copy data.
public:
	dynamic_array(const unsigned & = _DEFAULT_SIZE, const int & = 0);
	// Create a new dynamic_array with given size, and initialize it
	// with filling the given data.
	dynamic_array(const int *, const unsigned &);
	// Copy data from a normal array.
	explicit dynamic_array(const std::vector<int> &);
	// Copy data frome a STL vector.
	dynamic_array(const dynamic_array &);
	// Copy Constructor.

	~dynamic_array();

	int getSize() const;
	// Return the current size.

	int & operator[](const unsigned &);
	int operator[](const unsigned &) const;

	friend std::ostream & operator<<(std::ostream &,
		const dynamic_array &);
	// Output Format:
	// 0 1 2 3 ...
	// No extra space at the end of a line. Nor LF.
};

#endif
