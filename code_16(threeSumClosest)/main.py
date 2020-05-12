'''
我本以为用hashmap会快一点
结果发现hashmap毫无用出，用hashmap去重，然后发现这个列表里面应该是没有重复的
所以这种方法用起来就很失败
'''
class Solution:
	def threeSumClosest(self, nums: List[int], target: int) -> int:
		nums.sort()
		hashmap=dict((index,value) for index,value in enumerate(nums))
		a,ans=0,float('inf')
		while a <len(hashmap)-2:
			b=a+1
			c=len(hashmap)-1
			while b<c:
				if abs(hashmap[a]+hashmap[b]+hashmap[c]-target)<abs(ans-target):
					ans=hashmap[a]+hashmap[b]+hashmap[c]
				if hashmap[a]+hashmap[b]+hashmap[c]-target==0:
					return target
				elif hashmap[a]+hashmap[b]+hashmap[c]-target<0:
					b+=1
				else: c-=1
			a+=1
		return ans



