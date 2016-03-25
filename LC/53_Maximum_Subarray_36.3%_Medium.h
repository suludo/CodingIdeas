/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            ret = max(ret, nums[i]);
            ret = max(ret, nums[i]+prev);
            prev = max(nums[i],nums[i]+prev);
        }
        return ret;
    }
};