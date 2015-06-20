#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <cstdlib>

#define nullptr NULL

class myDeque {
private:
	struct listNode {   // Double Linked List
		listNode * _succ, *_prep;
		int _x;
		listNode(const int & x,
			listNode * prep = nullptr, listNode * succ = nullptr) :
			_x(x), _prep(prep), _succ(succ) {}
	} *_head, *_tail;
	int _size;
public:
	explicit myDeque();
	// Create an empty dequeue.
	myDeque(const myDeque &);
	// Copy Constructor.

	~myDeque();

	int getSize() const;
	bool empty() const;
	int head() const;
	// Return the element at the front of the dequeue.
	int tail() const;
	// Return the element at the back of the dequeue.

	void push_front(const int &);
	// Push an element at the front of the dequeue.
	void push_back(const int &);
	// Push an element at the back of the dequeue.
	bool pop_front();
	// Pop an element at the front of the dequeue.
	// Return false and do nothing if the dequeue is empty.
	// Otherwise, return true.
	bool pop_back();
	// Pop an element at the back of the dequeue.
	// Return false and do nothing if the dequeue is empty.
	// Otherwise, return true.
};

#endif