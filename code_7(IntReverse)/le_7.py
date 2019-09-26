class Solution:
    def reverse(self, x: int) -> int:
        if x>=0:
            string=str(x)
            string=string[::-1]
            if 0<=int(string)<=2147483647:
                return int(string)
            else: 
                return 0
        else:
            string=str(0-x)
            string=string[::-1]
            string='-'+string
            if 0>=int(string)>=-2147483648:
                return int(string)
            else:
                return  0
s=Solution()
print(s.reverse(-123))