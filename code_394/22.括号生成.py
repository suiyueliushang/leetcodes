#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#

# @lc code=start
class Solution:
	def generateParenthesis(self, n: int) -> List[str]:
		res=[]
		def backtrace(list,left,right):
			if left==right and left==n:
				res.append(list)
			if left<n:
				backtrace(list+"(",left+1,right)
			if right<left:
				backtrace(list+")",left,right+1)
		
		backtrace("",0,0)
		return res
	
