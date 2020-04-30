/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * function MountainArray() {
 *     @param {number} index
 *     @return {number}
 *     this.get = function(index) {
 *         ...
 *     };
 *
 *     @return {number}
 *     this.length = function() {
 *         ...
 *     };
 * };
 */

/**
 * @param {number} target
 * @param {MountainArray} mountainArr
 * @return {number}
 */
var findInMountainArray = function(target, mountainArr) {
	var length=mountainArr.length();
	if(target<mountainArr.get(0)&&target<mountainArr.get(length-1))
		return -1;
	var mid,left=1,right=length-2,max,maxV;
	while(left<=right){
		mid=parseInt((left+right)/2);
		var a;
		if((a=mountainArr.get(mid))>mountainArr.get(mid-1)){
			if(a>mountainArr.get(mid+1)){
				max=mid;
				maxV=a;
                break;
			}
			else left=mid+1;
		}
		else
			right=mid-1;
	}
	if(target>maxV) return -1;
	return (b=searchL(0,max,target))!=-1 ? b:searchR(max,length-1,target);

	function  searchL(l,r,t){
		var left=l,right=r,mid;
		while(left<=right){
			mid=parseInt((left+right)/2);
            console.log(mid);
			if((c=mountainArr.get(mid))==t)
				return mid;
			else if(c<t)
				left=mid+1;
			else right=mid-1;
		}
		return -1;
	}

	function searchR(l,r,t){
		var left=l,right=r,mid;
		while(left<=right){
			mid=parseInt((left+right)/2);
			if((c=mountainArr.get(mid))==t)
				return mid;
			else if(c<t)
				right=mid-1;
			else left=mid+1;
		}
		return -1;
	}
};
