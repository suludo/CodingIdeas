//
//  209_MinimumSizeSubarraySum.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _09_MinimumSizeSubarraySum_h
#define _09_MinimumSizeSubarraySum_h


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0, r=0, ret = INT_MAX, sum = 0;
        int n = nums.size();
        
        while(r<n){
            sum += nums[r++];
            while(sum>=s){
                ret = min(ret, r-l);
                sum -= nums[l++];
            }
        }
        return ret==INT_MAX ? 0:ret;
    }
};


#endif /* _09_MinimumSizeSubarraySum_h */
