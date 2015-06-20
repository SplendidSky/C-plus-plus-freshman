#include <iostream>
#include "hasCycle.h"

using namespace std;

void deleteNode(ListNode *head, int i, const int &max) {
	if (head == NULL || i >= max) {
		return;
	}
	else {
		ListNode *next = head->next;
		delete head;
		deleteNode(next, i + 1, max);
	}
}

int main() {
	/*
	has cycle
	_______
	/       \
	/         \
	1-->2-->3-->4

	*/
	{
		ListNode *head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = head;
		cout << hasCycle(head) << endl;
		deleteNode(head, 0, 4);
	}
	/*
	has cycle
	_
	/ \
	1-->2-->3
	*/

	{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = head->next;
	cout << hasCycle(head) << endl;
	deleteNode(head, 0, 3);
}
	/*
	no cycle

	1-->2-->3-->4-->NULL
	*/
	{
		ListNode *head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		cout << hasCycle(head) << endl;
		deleteNode(head, 0, 4);
	}
	/*
	no cycle

	1-->1-->1-->1-->NULL
	*/
	{
		ListNode *head = new ListNode(1);
		head->next = new ListNode(1);
		head->next->next = new ListNode(1);
		head->next->next->next = new ListNode(1);
		cout << hasCycle(head) << endl;
		deleteNode(head, 0, 4);
	}
	return 0;
}
