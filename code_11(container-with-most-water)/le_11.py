'''
date：2019/9/27
双指针法：
'''
class Solution:
    def maxArea(self, height) -> int:
        i=0
        j=len(height)-1
        maxArea=0
        while i<j:
            maxArea=max((j-i)*min(height[i],height[j]),maxArea)
            if height[i]-height[j]>=0:
                j-=1
            else:
                i+=1
        return maxArea
s=Solution()
print(s.maxArea([1,8,6,2,5,4,8,3,7]))
