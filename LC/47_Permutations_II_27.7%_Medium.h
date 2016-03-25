/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
//pass by ref and pass by val for num
class Solution {
public:

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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > ret;
        helper(nums, 0, ret);
        return ret;
    }
};



class Solution {
public:
    void helper(vector<int>& nums, vector<int>& path, vector< vector<int> >& res){
        if(nums.empty()){
            if(path.empty()==false)
                res.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int del = nums[i];
            path.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            helper(nums, path, res);
            path.pop_back();
            nums.insert(nums.begin()+i, del);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector< vector<int> > ret;
        helper(nums, path, ret);
        return ret;
    }
};