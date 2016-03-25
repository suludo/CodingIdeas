/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
class Solution {
public:
    void helper(vector<int>& c, int start, int curSum, int target, vector<int>& path, vector<vector<int>>& res){
        if(curSum>target) return;
        if(curSum==target){
            res.push_back(path);
            return;
        }
        for(int i=start; i<c.size(); i++){
            if(i>start && c[i]==c[i-1]) continue;
            path.push_back(c[i]);
            helper(c, i, curSum+c[i], target, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if(candidates.empty()) return ret;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(candidates, 0, 0, target, path, ret);
        return ret;
    }
};