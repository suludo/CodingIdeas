//
//  81_SearchInRotatedSortedArrayII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/16/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _1_SearchInRotatedSortedArrayII_h
#define _1_SearchInRotatedSortedArrayII_h

//BEAR IN MIND, binary search can always use l<r as boundary
//at least that s easy for me to remember

//remmeber point is partition based on comparison btw nums[m] and nums[r]
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(target==nums[m]) return true;
            if(nums[m]<nums[r]){
                if(nums[m]<target && nums[r]>=target) l = m+1;
                else r = m-1;
            }
            else if(nums[m]>nums[r]){
                if(nums[m]>target && nums[l]<=target) r = m-1;
                else l = m+1;
            }
            else r--;
        }
        return nums[l]==target;
    }
};

#endif /* _1_SearchInRotatedSortedArrayII_h */
