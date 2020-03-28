class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        length=words.__len__()
        s2={}
        if length<=0:
            return 0
        s=list(set(words));
        for i in s:
            for j in range(1,i.__len__()):
                if i[j:] in s:
                    s.remove(i[j:])
        count=0
        for i in s:
            count+=i.__len__()+1
        return count