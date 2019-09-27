'''
@date:2019/9/27
回溯解法，耗时间且耗空间
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:#终止条件，为空时
            return not s
        temp=bool(s) and p[0] in [s[0],'.']
        if len(p)>=2 and'*'==p[1]:#当长度大于1，切p第二个元素为*
            return (temp and self.isMatch(s[1:],p)) or self.isMatch(s,p[2:])
        else:#p长度大于2，且第二个元素不为*
            return temp and self.isMatch(s[1:],p[1:])
