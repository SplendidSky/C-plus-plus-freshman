#ifndef STACK_H
#define STACK_H

template <typename ElementType>
class Stack {
public:
	Stack() : top(nullptr) {}
	void push(ElementType ele);
	ElementType pop();
	ElementType peek();
	bool empty();
	~Stack();
private:
	struct Node {
		ElementType value;
		Node *down;
	};
	Node *top;
};

#endif