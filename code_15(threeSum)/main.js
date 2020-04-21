/**先排序，先定最左边的元素，然后调节右边两项，使三项和为0
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
	length=nums.length;
	if(length<3)return [];
	nums.sort((a,b)=>a-b);
	res=new Array()
	for(var i=0;i<length-2;i++){
		if(i>0){
			if(nums[i]==nums[i-1]){
				while(nums[i]==nums[i-1])
					i++;
				i--;
				continue;
			}
		}
		if(nums[i]>0)break;
		var left=i+1,right=length-1;
		while(left<right){
			if(nums[i]+nums[left]+nums[right]==0){
				res.push([nums[i],nums[left],nums[right]]);
				if(nums[left]==nums[right])break;
				left++;
				while(nums[left]==nums[i])
					left++;
				if(nums[left]==nums[left-1])
					while(nums[left]==nums[left-1])
						left++;
				right--;
			}
			else if(nums[i]+nums[left]+nums[right]>0)
				right--;
			else
				left++;
		}
	}
	return res;
};
