''''
摘自leetcode运行时间榜首，由于运用了hashmap，所以运行时间只有52ms,其速度比main中的方法快了40多倍
'''
class Solution:
	def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
		nums.sort() # 排序放在前面，建立字典得是在排序之后建立
		length = len(nums)
		if length == 0: return []
		hashmap = dict((value,index) for index,value in enumerate(nums)) # 注意 这么创建完字典后，重复的值都将被覆盖
		# print(hashmap)
		# 设置一个集合，用于放最终结果，使用集合可以产生去重复的效果
		res = set() 
		
		max_num = nums[-1]
		for i in range(length-3):
			a = nums[i]
			if a + 3 * max_num < target: continue # 当最小的数和3倍最大的数加一起还比目标值小的话，证明这个数a和其他的组合也不可能达到目标值，所以需要更大的数，则开始下一次循环
			if 4 * a > target: break # 如果当最小的数的4倍就比目标值大，则退出循环，直接输出没有符合答案的解
			for j in range(i+1,length-2):
				b = nums[j]
				if a + b + 2 * max_num < target: continue
				if a + 3 * b > target: break
				for k in range(j+1,length-1):
					c = nums[k]
					d =target - (a + b + c)
					if d > max_num: continue
					if d < c: break
					if d in hashmap and hashmap[d]>k:
						res.add((a,b,c,d))
		return list(res)