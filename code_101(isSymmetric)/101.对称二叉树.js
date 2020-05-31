/*
 * @lc app=leetcode.cn id=101 lang=javascript
 *
 * [101] 对称二叉树
 */

// @lc code=start

//Definition for a binary tree node.
function TreeNode(val) {
	this.val = val;
	this.left = this.right = null;
}


/** @param { TreeNode } root
	* @return { boolean }
*/
var isSymmetric = function (root) {
	if (!root) return true;
	return isSymmetricTwoTree(root.left, root.right);
};

var isSymmetricTwoTree = function (left_root, right_root) {
	if (!left_root && !right_root) return true;
	if (left_root && right_root) {
		if (left_root.val == right_root.val) {
			if (isSymmetricTwoTree(left_root.left, right_root.right) && isSymmetricTwoTree(left_root.right, right_root.left))
				return true;
		}
	}
	return false;
};
// @lc code=end

