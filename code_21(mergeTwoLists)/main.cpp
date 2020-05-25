#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1)return l2;
		if(!l2)return l1;
		ListNode* a=l1,*b=l2,*res_head=(a->val<=b->val?a:b),*res=res_head;
		a->val<=b->val?a=a->next:b=b->next;
		while(a&&b)
		{
			if(a->val<=b->val){
				res->next=a;
				res=res->next;
				a=a->next;
			}
			else{
				res->next=b;
				b=b->next;
				res=res->next;
			}
		}
		if(a)res->next=a;
		else if(b)res->next=b;
		return res_head;
	}
	/**
	 * 递归解法
	 */
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1)return l2;
		if(!l2)return l1;
		l1->val<=l2->val? l1->next=mergeTwoLists(l1->next,l2):l2->next=mergeTwoLists(l1,l2->next);
		return l1->val<=l2->val?l1:l2;
	}
};

int main()
{
	ListNode a1=ListNode(2);
	ListNode b1=ListNode(1);
	Solution s;
	s.mergeTwoLists(&a1,&b1);
}