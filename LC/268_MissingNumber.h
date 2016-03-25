//
//  268_MissingNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/18/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _68_MissingNumber_h
#define _68_MissingNumber_h

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i=0; i<nums.size(); i++)
            result ^= i^nums[i];
        
        return result;
    }
};


#endif /* _68_MissingNumber_h */
