/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.size()==1) return target == nums[0] ? 0:-1;
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target)
                return mid;
                
            if(nums[mid]>target){
                if(nums[l]>target && nums[l]<=nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else{
                if(nums[r]<target && nums[r]>=nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return nums[l]==target ? l:-1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            
            if(nums[m]==target) return m;
            
            if(nums[m]<nums[r]){
                if(nums[m]<target && nums[r]>=target)
                    l = m+1;
                else //nums[m] should only be larger than target
                    r = m-1;
            }
            else if(nums[m]>nums[r]){
                if(nums[m]>target && nums[l]<=target)
                    r = m-1;
                else //nums[m] should be only less than target in this ELSE
                     //otherwise it will return true in LINE 11 immediately
                    l = m+1;
            }
            else
                r--;
        }
        return -1;
    }
};