'''
@date:2019/9/27
动态规划的解决方法：用一个二位数组存储之前计算结果，减少重复运算
运行效率提高了20多倍
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        S=len(s)
        P=len(p)
        dp_list=[[-1 for i in range(P+1)] for j in range(S+1)]
        def dp(i,j):
            if dp_list[i][j]!=-1:
                return dp_list[i][j]
            if j==P:return i==S #p为空
            #p不为空
            temp=i<S and p[j] in [s[i],'.']
            if j<P-1 and p[j+1]=='*':
                ans=(temp and dp(i+1,j)) or dp(i,j+2)
            else:
                ans= temp and dp(i+1,j+1)
            dp_list[i][j]=ans
            return ans
        return dp(0,0)
