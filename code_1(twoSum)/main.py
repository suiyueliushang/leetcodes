class Solution:
	def twoSum(self, nums:list, target: int):
			d=dict()
			for i in range(0,nums.__len__()):
				d[nums[i]]=i;
				if d.__contains__(target-nums[i]):
					return [i,d[target-nums[i]]]
			return []