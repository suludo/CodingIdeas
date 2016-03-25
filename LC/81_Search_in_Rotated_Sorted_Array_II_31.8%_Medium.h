/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
//choose this solution, as compare between  m and r and target

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            
            if(nums[m]==target) return true;
            
            if(nums[m]<nums[r]){
                if(nums[m]<target && nums[r]>=target)
                    l = m+1;
                else //nums[s] should only be larger than target
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
        return false;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(nums.size()==1) return target == nums[0];
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target)
                return true;
                
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
        return nums[l]==target;
    }
};

class Solution {
public:
    bool search(vector<int>& A, int key) {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (A[m] == key) return true; //return m in Search in Rotated Array I
            if (A[l] < A[m]) { //left half is sorted
                if (A[l] <= key && A[m] > key)
                //if (A[l] < key && A[m]>=key)
                    r = m - 1;
                else
                    l = m;
            } else if (A[l] > A[m]) { //right half is sorted
                if (A[m] < key && A[r] >= key)
                    l = m + 1;
                else
                    r = m;
            } else l++;
        }
        return false;
    }
};

