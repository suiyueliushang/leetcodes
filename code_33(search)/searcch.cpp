#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int length=nums.size();
		if(length==0)return -1;
		int left=0,right=length-1,mid;
		while (left<=right)
		{
			mid=(left+right)/2;
			if(nums[mid]==target)return mid;
			if(nums[mid]>=nums[left])
				if(target>=nums[left])
					return binarySearch(nums,target,left,mid-1);
				else right=mid+1;
			else if(nums[mid]<=nums[right])
				if(target>=nums[mid])return binarySearch(nums,target,mid+1,right);
				else left=mid-1;
		}
		return -1;
	}
	int binarySearch(vector<int>& nums, int target,int left,int right){
		int mid;
		while(left<=right){
			mid=(left+right)/2;
			if(target==nums[mid])
				return mid;
			else if(target<nums[mid])
				right=mid-1;
			else 
				left=mid+1;
		}
		return -1;
	}
};

