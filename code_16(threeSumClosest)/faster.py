'''
看了运行时榜首的代码，主要思路也是外层循环加双指针，但是在循环中进行判断，
减去了很多不必要的循环
'''
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums)<3:
            return False
        if len(nums)==3:
            return nums[0]+nums[1]+nums[2]
        nums.sort()
        ans= nums[0]+nums[1]+nums[2]#先初始化为无穷大，以便于后续比较
        for a in range(len(nums)-2):
            b=a+1
            c=len(nums)-1
            if nums[a]+nums[a+1]+nums[a+2]>target:#最小的大于target
                if abs(nums[a]+nums[a+1]+nums[a+2]-target)<abs(ans-target):
                    ans=nums[a]+nums[a+1]+nums[a+2]
                break
            elif nums[a]+nums[-1]+nums[-2]<target:
                if abs(nums[a]+nums[-1]+nums[-2]-target)<abs(ans-target):
                    ans=nums[a]+nums[-1]+nums[-2]
                continue
            while b<c:
                temp=nums[a]+nums[b]+nums[c]
                if abs(temp-target)<abs(ans-target):
                    ans=temp
                if temp==target:#至关重要的判断，让运行时间缩短到1/4
                    return target
                elif temp<target:
                    b+=1
                else:c-=1
        return ans