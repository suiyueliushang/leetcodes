class Solution {
public:
	int search(vector<int>& nums, int target) {
		int length=nums.size();
		if(length<=2)
		{
			int l=0,r=length-1;
			if(target==nums[l])return 0;
			if(target==nums[r])return r;
			return -1;
		}
		int  left=1,right=length-2,mid,max;
		while(left<=right){
			mid=(left+right)/2;
			if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1]){
				max=mid-1;
				break;
			}
			else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
				max=mid;
				break;
			}
			else if(nums[mid]>nums[0]){
				left=mid+1;
				continue;
			}
			else if(nums[mid]<nums[length-1]){
				right=mid-1;
				continue;
			}
		}
		if(nums[length-1]>nums[0])max=length-1;
		if(target>=nums[0]){
			left=0,right=max;
		}
		else
			left=max+1,right=length-1;
		cout<<left<<" "<<right<<endl;
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