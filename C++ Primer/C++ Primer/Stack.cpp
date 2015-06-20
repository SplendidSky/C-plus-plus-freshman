#include "Stack.h"

template<typename ElementType>
void Stack<ElementType>::push(ElementType ele) {
	if (empty()) {
		top = new Node;
		top->value = ele;
		top->down = nullptr;
	}
	else {
		auto temp = top;
		top = new Node;
		top->value = ele;
		top->down = temp;
	}
}

template<typename ElementType>
ElementType Stack<ElementType>::pop() {
	if (top != nullptr) {
		auto temp = top;
		auto v = top->value;
		top = top->down;
		delete temp;
		return v;
	}
	cout << "The stack is empty !" << endl;
}

template<typename ElementType>
bool Stack<ElementType>::empty() {
	return top == nullptr;
}

template<typename ElementType>
ElementType Stack<ElementType>::peek() {
	return top->value;
}

template<typename ElementType>
Stack<ElementType>::~Stack() {
	while (top != nullptr)
		delete top;
}