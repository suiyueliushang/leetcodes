class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target){
		int leftMost=-1,left=0,right=nums.size()-1,mid;
		vector<int>res;
		while(left<=right){
			int mid=(left+right)/2;
			if(nums[mid]==target){
				right=mid-1;
				leftMost=mid;
			}
			else if(nums[mid]>target)
				right=mid-1;
			else left=mid+1;
		}
		if(leftMost==-1){
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		int rightMost=-1,left=leftMost,right=nums.size()-1;
		while(left<=right){
			mid=(left+right)/2;
			if(nums[mid]==target){
				left=mid+1;
				rightMost=mid;
			}
			else if(nums[mid]>target)
				right=mid-1;
			else left=mid+1;
		}
		res.push_back(leftMost);
		res.push_back(rightMost);
		return res;
	}
};