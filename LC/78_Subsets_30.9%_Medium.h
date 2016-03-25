/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    void helper(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res){
        res.push_back(path);
        if(start==nums.size()) return;
        for(int i=start; i<nums.size(); i++){
            path.push_back(nums[i]);
            helper(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        helper(nums, 0, path, ret);
        return ret;
    }
};