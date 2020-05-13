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
	var ans=[];
	bfs(root,0,ans);
	return ans;
}
function bfs(node,levle,ans){
	if(!node)return;
	if(!ans[levle])ans[levle]=[]
	ans[levle].push(node.val);
	bfs(node.left,levle+1,ans);
	bfs(node.right,levle+1,ans);
}
