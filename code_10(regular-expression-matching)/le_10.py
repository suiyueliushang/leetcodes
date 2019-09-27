'''
@date:2019/9/27
回溯解法，耗时间且耗空间
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:#终止条件，为空时
            return not s
        if len(p)==1:#当长度为1两个条件满足才可
            return bool(s) and p[0] in['.',s[0]] and len(s)==1 
        elif '*'==p[1]:#当长度大于1，切p第二个元素为*
            if not s:#s为空
                return self.isMatch(s,p[2:])
            return (p[0] in [s[0],'.'] and self.isMatch(s[1:],p)) or self.isMatch(s,p[2:])
        else:#p长度大于2，且第二个元素不为*
            match=bool(s) and p[0] in [s[0],'.'] 
            return match and self.isMatch(s[1:],p[1:])
