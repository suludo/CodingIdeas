//
//  228_SummaryRanges.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _28_SummaryRanges_h
#define _28_SummaryRanges_h


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, size = nums.size();
        vector<string> result;
        while(i < size){
            int j = 1;
            while(i + j < size && (nums[i + j] - nums[i]) == j) ++j;
            result.push_back(j == 1 ? to_string(nums[i]) : (to_string(nums[i]) + "->" + to_string( nums[i + j - 1] )) );
            i += j;
        }
        return result; 
    }
};

#endif /* _28_SummaryRanges_h */
