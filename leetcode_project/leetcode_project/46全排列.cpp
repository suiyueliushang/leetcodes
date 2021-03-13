#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, 0, nums);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, int first, vector<int>& nums) {
        if (first == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); i++) {
            swap(nums[first], nums[i]);
            dfs(ans, first+1, nums);
            swap(nums[first], nums[i]);
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
