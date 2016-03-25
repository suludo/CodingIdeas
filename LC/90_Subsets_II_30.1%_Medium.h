/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
// 1. res.push_back(path) put in the first line to include empty set
// 2. don't forget the sort(nums.begin(), nums.end())
    void helper(vector<int>& nums, int start, vector<int>& path, vector< vector<int> >& res){
        
        res.push_back(path);
        //this line, though working, is not needed
        //if(start>=nums.size()) return;
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > ret;
        vector<int> path;
        //ret.push_back(path);
        helper(nums, 0, path, ret);
        return ret;
    }
};