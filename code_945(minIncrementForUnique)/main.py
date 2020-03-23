class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        i,count=0
        l=[0]*4000
        for i in A:
            l[i]+=1;
        for i in l:
            if i>1:
                count+=i-1
                l[i+1]+=i-1
        return count
        
