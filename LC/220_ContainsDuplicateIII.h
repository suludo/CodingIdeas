//
//  220_ContainsDuplicateIII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _20_ContainsDuplicateIII_h
#define _20_ContainsDuplicateIII_h


/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // <Value, Index>
        map<int, int> mp;
        int l = 0;
        for(int r=0; r<nums.size(); r++){
            if(r-l>k) mp.erase(nums[l++]);
            auto it = mp.lower_bound(nums[r]-t);
            
            if(it != mp.end() && abs(nums[r]-it->first)<=t)
                return true;
            mp[nums[r]] = r;
        }
        return false;
    }
};

#endif /* _20_ContainsDuplicateIII_h */
