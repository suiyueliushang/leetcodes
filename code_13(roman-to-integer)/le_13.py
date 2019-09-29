class Solution:
    def romanToInt(self, s: str) -> int:
        #罗马数字转换为整数
        dict={'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,
        'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        integer=0   

        i=0
        while i<len(s):
            if i<len(s)-1:#当不为最后一个字符时 
                if dict.__contains__(s[i:i+2]):#先判断连续两个的
                    integer+=dict[s[i:i+2]]
                    i+=2
                    continue
            integer+=dict[s[i]]
            i+=1
        return integer
