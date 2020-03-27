class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if not deck:return False
        dict={}
        for i in deck:
            dict[i]=dict.setdefault(i,0)+1
        l=list(dict.values())
        max=l[0]
        for i in range(1,l.__len__()):
            max=self.gcd(max,l[i])
        if max>=2:
            return True
        else:return False
            
    def gcd(self,x:int,y:int)->int:
        if x==0:
            return y
        else:
            return gcd(y%x,x)