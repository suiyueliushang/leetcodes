class Solution:
    def convert(self, s: str, numRows: int) -> str:
        length=len(s)
        A=2*numRows-2#每列元素数
        if numRows==1:
            return s
        #宽度判断
        wid=int(length/A)
        left=length%A
        res=''
        if numRows==2:
                for j in range(0,wid):
                    res+=s[j*A]
                if left==1:
                    res+=s[wid*A]
                for j in range(0,wid):
                    res+=s[j*A+1]
                return res
        for i in range(0,numRows):#行进行循环
            if i==0:
                for j in range(0,wid):
                    res+=s[j*A]
                if left>0:
                    res+=s[wid*A]
            elif i==numRows-1:#最后一行
                for j in range(0,wid):
                    res+=s[j*A+numRows-1]
                #最后一列处理
                if left>=numRows:
                    res+=s[wid*A+numRows-1]
            else:#中间其它行
                for j in range(0,wid):#列循环
                    res+=s[j*A+i]+s[j*A+i+2*(numRows-i-1)]
                if left>numRows:#最后一列处理
                    res+=s[wid*A+i]
                    if left-numRows+i>numRows-2:
                        res+=s[wid*A+i+2*(numRows-i-1)]
                elif left>0:#剩余小于行数
                    if i<left:
                        res+=s[wid*A+i]
        return res            
