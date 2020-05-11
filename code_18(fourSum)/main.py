class Solution:
	def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
		nums.sort()
		a,b=0,1
		ans=[]
		while a<len(nums)-3:
			if a!=0:
				if nums[a]==nums[a-1]:
					a+=1
					continue
			b=a+1
			while b<len(nums)-2:
				if b!=a+1 and nums[b]==nums[b-1]:
					b+=1
					continue
				left=b+1
				right=len(nums)-1
				while left<right:
					if nums[a]+nums[b]+nums[left]+nums[right]==target:
						ans.append([nums[a],nums[b],nums[left],nums[right]])
						left+=1
						while left<right and nums[left]==nums[left-1]:
							left+=1
						right-=1
						while left<right and nums[right]==nums[right+1]:
							right-=1
					elif nums[a]+nums[b]+nums[left]+nums[right]<=target:
						left+=1
					elif nums[a]+nums[b]+nums[left]+nums[right]>=target:
						right-=1
				b+=1
			a+=1
		return ans
				
s=Solution()
print(s.fourSum([1, 0, -1, 0, -2, 2],0))