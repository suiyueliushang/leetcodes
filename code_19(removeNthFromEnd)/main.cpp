#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head | !head->next) return NULL;
		ListNode* fast = head;
		ListNode* slow = head;
		for (int i = 0; i < n; i++)
			fast = fast->next;
		if (!fast)
			return slow->next;
		for (; fast->next; fast = fast->next, slow = slow->next);
		slow->next = slow->next->next;
		return head;
	}
};
int main()
{

	return 0;
}