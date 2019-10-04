class Solution:
    def threeSum(self, nums: [int]) -> [[int]]:
        #对nums进行排序：
        if len(nums)<3:
            return []
        def fastSort(n:[int])->[int]:
            #特殊返回
            l=len(n)
            if l<=1:
                return n
            left,right=[],[]
            mid=n[l//2]
            n.__delitem__(l//2)
            for i in n:
                if i>mid:
                    right.append(i)
                else:
                    left.append(i)
            return fastSort(left)+[mid]+fastSort(right)
        nums=fastSort(nums)
        minus,zero,plus=[],0,[]
        for i in nums:
            if i<0:
                minus.append(i)
            elif i==0:
                zero+=1
            else:
                plus.append(i)
        res=[]
        #一零一正一负，三个零
        if zero>0:
            if zero>=3:
                res.append([0,0,0])
            for j in minus:
                if -j in plus:
                    res.append([j,0,-j])
        #两负一正，两正一负
        if len(minus)>1:
            for i in range(1,len(minus)):
                for j in range(0,i):
                    if 0-minus[i]-minus[j] in plus:
                        res.append([minus[i],minus[j],0-minus[i]-minus[j]])
        if len(plus)>1:
            for i in range(1,len(plus)):
                for j in range(0,i):
                    if 0-plus[i]-plus[j] in minus:
                        res.append([plus[i],plus[j],0-plus[i]-plus[j]])
        if len(res)>1:
            temp=[]
            for i in range(len(res)):
                if res[i] not in temp:
                    temp.append(res[i])
            return temp
        return res            
print(Solution().threeSum([-1,0,1,2,-1,-4]))