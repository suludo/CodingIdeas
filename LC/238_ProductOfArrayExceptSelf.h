//
//  238_ProductOfArrayExceptSelf.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _38_ProductOfArrayExceptSelf_h
#define _38_ProductOfArrayExceptSelf_h


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return nums;
        vector<int> ret(nums.size(), 1);
        
        for(int i=1; i<nums.size(); i++)
            ret[i] = nums[i-1]*ret[i-1];
        
        int cur = 1;
        for(int i=ret.size()-2; i>=0; i--){
            cur *= nums[i+1];
            ret[i] *= cur;
        }
        
        return ret;
    }
};


#endif /* _38_ProductOfArrayExceptSelf_h */
