#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res=c=ListNode(0)
        a=l1
        b=l2
        count=0
        while not a and not b:
            c=a.val+b.val+count
            count=c/10
            c=c%10
            c.next=ListNode(0)
            a=a.next
            b=b.next
            c=c.next
        if count==1:
            
        if not a:
            c=b
        else: c=a
        return res