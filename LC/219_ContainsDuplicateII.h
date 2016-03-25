//
//  219_ContainsDuplicateII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _19_ContainsDuplicateII_h
#define _19_ContainsDuplicateII_h


/*Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp; //smallest index of mp[i]
        
        for(int i=0; i<nums.size(); i++){
            int ni = nums[i];
            if(mp.find(ni)!=mp.end() && i-mp[ni]<=k)
                return true;
            mp[ni]=i;
        }
        return false;
    }
};
#endif /* _19_ContainsDuplicateII_h */
