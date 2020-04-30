class Solution:
		def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
			res=[]
			table={}
			a=["Table"]
			for i in orders:
				if i[2] not in a:
					a.append(i[2])
				if i[0] not in table:
					table          
				