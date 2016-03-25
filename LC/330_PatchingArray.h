//
//  330_PatchingArray.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _30_PatchingArray_h
#define _30_PatchingArray_h

class Solution {
public:
    //https://leetcode.com/discuss/82822/solution-explanation
    int minPatches1(vector<int>& nums, int n) {
        int i = 0;
        long curMax = 1; // [0,curMax) nums[0..i] can form
        int ret = 0;
        while(curMax<=n){
            if(i<nums.size() && nums[i]<=curMax)
                curMax += nums[i++];
            else{
                curMax += (curMax);
                ret++;
            }
        }
        return ret;
    }
    
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        long curMax = 0; // [0,curMax] nums[0..i] can form
        int ret = 0;
        while(curMax<n){
            if(i<nums.size() && nums[i]<=(curMax+1))
                curMax += nums[i++];
            else{ // reach array end, or nums[i]>(curMax+1), i.e. no value to form curMax+1 onwards
                curMax += (curMax+1);
                ret++;
            }
        }
        return ret;
    }
};


#endif /* _30_PatchingArray_h */
