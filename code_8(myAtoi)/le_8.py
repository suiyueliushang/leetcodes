import re
class Solution:
    def myAtoi(self, str: str) -> int:
        matchOj=re.match('\s*(\d+)|\s*(-\d+)|\s*(\+\d+)',str)
        if matchOj:
            string=matchOj.group(0)
            if -2147483648<=int(string)<=2147483647:
                return int(string)
            else:#数据溢出
                if int(string)>0:
                     return 2147483647
                else:
                    return -2147483648
        else:#不匹配
            return 0