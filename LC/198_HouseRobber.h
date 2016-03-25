//
//  198_HouseRobber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _98_HouseRobber_h
#define _98_HouseRobber_h


//dp only uses the last two steps

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int m1 = max(nums[1],nums[0]);
        int m2 = nums[0];
        int ret = m1;
        for(int i=2; i<nums.size(); i++){
            ret = max(m2+nums[i], m1);
            m2 = m1;
            m1 = ret;
        }
        return ret;
    }
};



#endif /* _98_HouseRobber_h */
