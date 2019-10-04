class Solution:
    def longestCommonPrefix(self, strs: [str]) -> str:
        if  not strs:
            return ''
        lc=strs[0]
        for i in strs:
            j=0
            a=min(len(lc),len(i))
            while j<a and lc[j]==i[j]:
                j+=1
            lc=lc[0:j]
            if lc=='':
                return ''
        return lc
    
