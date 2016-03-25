//
//  217_ContainsDuplicate.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _17_ContainsDuplicate_h
#define _17_ContainsDuplicate_h



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end())
                return true;
            mp.insert(nums[i]);
        }
        return false;
    }
    
    bool _containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

#endif /* _17_ContainsDuplicate_h */
