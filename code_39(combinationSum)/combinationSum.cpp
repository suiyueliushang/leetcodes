#include <vector>
using std::vector;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>ans;
		vector<int>curr;
		dfs(target,ans,candidates,curr,0);
		return ans;
	}
	void dfs(int target,vector<vector<int>>&combinSum,vector<int>&candidates,vector<int>&current,int index){
		if(index==candidates.size())return;
		if(!target){
			combinSum.emplace_back(current);
			return;
		}
		dfs(target,combinSum,candidates,current,index+1);
		if(target>=candidates[index]){
			current.emplace_back(candidates[index]);
			dfs(target-candidates[index],combinSum,candidates,current,index);
			current.pop_back();
		}
		}
};