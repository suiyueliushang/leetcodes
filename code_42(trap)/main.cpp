#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		int length = height.size();
		if (length <= 2)
			return 0;
		vector<int>left_max(length), right_max(length);
		left_max[0] = height[0];
		for (int i = 1; i < length; i++) {
			if (height[i] > left_max[i - 1])
				left_max[i] = height[i];
			else left_max[i] = left_max[i - 1];
		}
		right_max[length - 1] = height.back();
		for (int i = length - 2; i >= 0; i--) {
			if (height[i] > right_max[i + 1])
				right_max[i] = height[i];
			else right_max[i] = right_max[i + 1];
		}
		int res = 0;
		for (int i = 0; i < length; i++)
			res += (left_max[i] < right_max[i] ? left_max[i] : right_max[i]) - height[i];
		return res;
	}
	int trap_(vector<int>& height) {
		int lenght = height.size();
		int left = 0, right = height.size() - 1;
		int left_max = 0, right_max = 0;
		int res = 0;
		while (left < right) {
			if (height[left] < height[right]){
				if (height[left] > left_max)
					left_max = height[left];
				else 
					res += left_max - height[left++];
			}
			else {
				if (height[right] > right_max)
					right_max = height[right];
				else
					res += right_max - height[right--];
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << s.trap_(v);
}