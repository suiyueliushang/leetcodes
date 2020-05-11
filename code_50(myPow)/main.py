class Solution:
	def myPow(self, x: float, n: int) -> float:
		if x==0:
			return 1
		res,temp=1.0,x
		flag=n//abs(n)
		n=abs(n) 
		list=self.bin(n)
		for i in range(len(list)):
			if i==0:
				res=x**list[i]
			else:
				temp*=temp;
				res*=temp**list[i]
		if flag==-1:
			return 1/res
		return res
	
	def bin(self,x:int):
		res=[]
		while x!=0:
			res.append(x%2);
			x=x//2
		return res
	
	def quickMul(self,x:float,n:int)->float:
		res=1.0;
		x_attribute=x
		while n>0:
			if n%2>0:
				res*=x_attribute
			x_attribute*=x_attribute
			n>>=1
		return res

	#递归方法
	def recur(self,x:float,n:int)->float:
		if n==0:
			return 1
		elif n==1:
			return x
		elif n<0:
			n=-n
			x=1/x
		power=x if n&1 else 1
		return power*self.recur(x,n//2)**2
s=Solution()
print(s.quickMul(2.00000,10))
