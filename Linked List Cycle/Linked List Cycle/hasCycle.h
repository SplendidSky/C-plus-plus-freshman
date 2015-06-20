#include <cstdlib>
/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head);
