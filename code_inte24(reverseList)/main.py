# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	'''迭代方法实现
	'''
	def reverseList(self, head: ListNode) -> ListNode:
		if head==None or head.next==None: return head
		current_node=head
		next_node=head.next
		current_node.next=None
		while next_node:
			pre_node=current_node
			current_node=next_node
			next_node=next_node.next
			current_node.next=pre_node
		return current_node
	
	'''递归方法实现
	'''
	def reverseList(self, head: ListNode) -> ListNode:
		if head==None or head.next==None: return head
		p=self.reverseList(head.next)
		head.next.next=head
		head.next=None
		return p

			
		