#
# @lc app=leetcode.cn id=394 lang=python3
#
# [394] 字符串解码
#

# @lc code=start


class Solution:
    def decodeString(self, s: str) -> str:
        if s == None or s == "":
            return ""
        stack, left_bracket, number = [], [], []
        i = 0
        while i < s.__len__():
            if s[i].isalpha():
                stack.append(s[i])
            elif s[i] == '[':
                left_bracket.append(stack.__len__())
                stack.append('[')
            elif s[i].isdigit():
                dig = []
                while(s[i].isdigit()):
                    dig.append(s[i])
                    i += 1
                number.append(int("".join(dig)))
                i -= 1
            elif s[i] == ']':
                if left_bracket.__len__() == 0 or number.__len__() == 0:
                    return None
                else:
                    j = left_bracket.pop()
                    stack[j:] = list(number.pop()*stack[j+1:])
            else:
                stack.append(s[i])
            i += 1
        return ''.join(stack)
# @lc code=end


S = Solution()
print(S.decodeString("30[leet]"))
