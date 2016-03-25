/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        
        auto l = lower_bound(nums.begin(), nums.end(), target);
        if(l == nums.end() || *l>target){
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        auto r = upper_bound(nums.begin(), nums.end(), target);
        int il = l-nums.begin();
        int ir = r-nums.begin()-1;
        ret.push_back(il);
        ret.push_back(ir);
        return ret;
    }
};