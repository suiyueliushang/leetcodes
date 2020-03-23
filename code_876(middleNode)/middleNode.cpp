#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     *  遍历两次
     */ 
    ListNode* middleNode(ListNode* head) {
        int length;
        ListNode* node=head;
        for(length=0;node;node=node->next,length++);
        node=head;
        int mid=length/2;
        for(int i=0;i<mid;node=node->next,i++);
        return node;
    }
    
    /**
     *  快慢指针,时间、空间复杂度与两次遍历相差无几
     */ 
    ListNode* middleNode(ListNode* head) {
        ListNode* fast,slow=head;
        while(fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(!fast)
                return slow->next;
        }
        return slow;
    }

};