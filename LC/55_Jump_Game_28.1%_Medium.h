/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i=0, step = 0, curMax = 0, nextMax = 0;
        while(i<=curMax){
            step++;
            if(curMax>=n-1) return true;
            while(i<=curMax){
                nextMax = max(nextMax, i+nums[i]);
                i++;
            }
            curMax = nextMax;
        }
        return false;
    }
};