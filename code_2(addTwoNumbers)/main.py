#Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
		res=c=ListNode(0)
		count=0
		while l1 or l2:
			if not l1:
				temp=l2.val+count
				count=temp//10
				temp%=10
				c.val=temp
				l2=l2.next
			elif not l2:
				temp=l1.val+count
				count=temp//10
				temp%=10
				c.val=temp
				l1=l1.next
			else:
				a=l1.val
				b=l2.val 
				temp=a+b+count
				count=temp//10
				temp=temp%10
				c.val=temp
				l1=l1.next
				l2=l2.next
			if l1 or l2:
				c.next=ListNode(0)
				c=c.next
		if count==1:
			c.next=ListNode(1)
		
		return res