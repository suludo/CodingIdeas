/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
class Solution {
public:
    void helper(vector<int>& nums, int start, int target, int sum, vector<int>&path, vector<vector<int>> &res){
        if(sum>target)
            return;
        if(target==sum){
            if(!path.empty())
                res.push_back(path);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(nums, i+1, target, sum+nums[i], path, res);
            path.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> ret;
        helper(candidates, 0, target, 0, path, ret);
        return ret;
    }
};