
/*
 * @lc app=leetcode.cn id=198 lang=java
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
	public int rob(int[] nums) {
		if (nums == null || nums.length == 0)
			return 0;
		else if (nums.length == 1)
			return nums[0];
		else if (nums.length == 2)
			return nums[0] > nums[1] ? nums[0] : nums[1];
		int a = nums[0], b = nums[0] > nums[1] ? nums[0] : nums[1], c = b;
		for (int i = 2; i < nums.length; i++) {
			c = a + nums[i] > b ? a + nums[i] : b;
			a = b;
			b = c;
		}
		return c;
	}
}
// @lc code=end
