/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

//pass by ref and pass by val
//Both will work, as this will return distinct sequence for sure
//while in II only pass by ref will work, since it can't maintain increasing order
class Solution {
public:
    void helper1(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            swap(nums[i],nums[start]);
            helper(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    }
    void helper(vector<int> num, int i, vector<vector<int> > &res) {
        if (i >= num.size()) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < num.size(); k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            helper(num, i+1, res);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        helper(nums, 0, ret);
        return ret;
    }
};