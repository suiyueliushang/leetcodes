#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minIncrementForUnique(vector<int>& A) {
		if (A.empty())return 0;
		int count = 0;
		vector<int>a, b;
		a.push_back(A[0]);
		b[0] = 1;
		for (int i = 1, j = 0; i < A.size(); i++) {
			if (A[i] == A[i - 1])
				b[j]++;
			else {
				j++;
				a[j] = A[i];
				b[j] = 1;
			}
		}
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (b[i] > 1)
				count += b[i] - 1;
			b[i + 1] += b[i] - 1;
		}
		count += b[a.size() - 1] - 1;
		return count;
	}
	void sort(vector<int>& a) {
		int length = a.size();
		if (length <= 1)
			return;
		int mid = length / 2;
		vector<int>left, right;
		int i = 0;
		for (; i < mid - 1; i++)
			left[i] = a[i];
		for (; i < length; i++)
			right[i - mid] = a[i];
		sort(left);
		sort(right);
		a.clear();
		int j;
		for (i = 0, j = 0; i < mid && j < length - mid;)
		{
			if (left[i] >= right[j]) {
				a.push_back(right[j]);
				j++;
			}
			else
			{
				a.push_back(left[i]);
				i++;
			}
		}
		if (i < mid)
			for (; i < mid; i++)
				a.push_back(left[i]);
		else
			for (; j < length - mid; j++)
				a.push_back(right[j]);
	}
};

int main()
{
	vector<int> a;
	for (int i =10; i >0; i--)
		a.push_back(i);
	Solution s = Solution();
	s.sort(a);
	
}