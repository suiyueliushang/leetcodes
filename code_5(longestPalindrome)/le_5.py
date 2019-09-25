class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        :type s: str
        :rtype: str
        """
        if s=='':
            return ''

        string='#'.join('^'+s+'$')
        length=len(string)
        C,R=2,3
        max=[0,0,1]
        for i in range(3,length-1):
            if i<R:#在范围内
                #找到i堆对称点i_mirror：
                i_mirror=2*C-i
                temp=max[i_mirror]
                if temp+i>=R:#超右边界
                    temp=R-i
                    #进行左右拓展
                    while string[i+temp+1]==string[i-temp-1]:
                        temp+=1
                elif i_mirror-temp==1:#遇到左边界
                    #进行左右拓展               
                    while string[i+temp+1]==string[i-temp-1] :
                        temp+=1
            else:#刚好压线
                temp=0
                while string[i+temp+1]==string[i-temp-1]:
                        temp+=1
            max.append(temp)
            if max[i]+i>R:#需要更新边界和中心
                R=max[i]+i
                C=i
        max_i=1
        Cen=2
        for j in range(0,len(max)):
            if max[j]>max_i:
                max_i=max[j]
                Cen=j
        string=string[Cen-max_i:Cen+max_i+1]
        str=''
        for i in range(1,len(string),2):
            str+=string[i]
        return str
        
string=input()
S=Solution()
S.longestPalindrome(string)
        
