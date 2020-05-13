/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
	if(!root)return [];
	var que=[root],ans=[[root.val]],level=1;
	while(que.length){
		var i=0, k=que.length;
		ans[level]=[]
		while (i<k){
			var current_node=que.pop();
			if(current_node){
				if(current_node.left){
					ans[level].push(current_node.left.val);
					que.unshift(current_node.left);
				}
				if(current_node.right){
					ans[level].push(current_node.right.val);
					que.unshift(current_node.right);
				}
			}
			i++;
		}
		level++;
	}
	ans.pop()
	return ans;
};