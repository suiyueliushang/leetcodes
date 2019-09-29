class Solution:
    def intToRoman(self, num: int) -> str:
        str=''
        dict={1000:'M',900:'CM',500:'D',400:'CD',100:'C',90:'XC',
        50:'L',40:'XL',10:'X',9:'IX',5:'V',4:'IV',1:'I'}
        a=0
        while num>=1:
            last=num%10
            if dict.__contains__(last*10**a):
                str=dict[last*10**a]+str
            elif last>5:
                str=dict[5*10**a]+(last-5)*dict[10**a]+str
            else:
                str=last*dict[10**a]+str
            a+=1
            num=int(num/10)
        return str
