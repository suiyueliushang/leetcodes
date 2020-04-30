class Solution:
	def reformat(self, s: str) -> str:
		a=[]
		b=[]
		res=[]
		for i in range(len(s)):
			if s[i].isalpha():
				a.append(s[i])
			elif s[i].isdigit():
				b.append(s[i])
			else:pass
		if a.__len__()-b.__len__()>1 or a.__len__()-b.__len__()<-1:
			return ""
		elif a.__len__()>=b.__len__():
			for i in range(len(s)):
				if i%2:
					res.append(b[i//2])
				else:
					res.append(a[i//2])
		elif a.__len__()<b.__len__():
			for i in range(len(s)):
				if i%2:
					res.append(a[i//2])
				else:
					res.append(b[i//2])
		return "".join(res)