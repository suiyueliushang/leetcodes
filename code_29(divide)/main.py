class Solution:
	def divide(self, dividend: int, divisor: int) -> int:
		if dividend == -2147483648 and divisor == -1:
			return 2147483647
		count = 0
		if dividend < 0:
			count += 1
			dividend = -dividend
		if divisor < 0:
			count += 1
			divisor = -divisor
		return (-1) ** count * self.div(dividend, divisor,0)
	
	def div(self, dividend: int, divisor: int,quotient:int) -> int:
		if dividend < divisor:
			return quotient;
		a=0
		while dividend >= (divisor << a):
			a += 1
		return self.div(dividend - (divisor << (a - 1)), divisor, quotient + 2 ** (a - 1))
		
		

s = Solution()
print(s.divide(12, -3))
