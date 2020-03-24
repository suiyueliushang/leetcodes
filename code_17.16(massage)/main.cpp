#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int massage(vector<int>& nums) {
		if(nums.empty()) return 0;
		int length=nums.size();
		if(nums.size()==1)return nums[0];
		int * max_minute=new int[length];
		max_minute[length-1]=nums[length-1];
		max_minute[length-2]=nums[length-1]>nums[length-2]? nums[length-1]:nums[length-2];
		for(int i=length-3;i>=0;i--)
			max_minute[i]=(nums[i]+max_minute[i+2])>max_minute[i+1]?(nums[i]+max_minute[i+2]):max_minute[i+1];
		int res=max_minute[0];
		delete []max_minute;
		return res;
		
	}
};
