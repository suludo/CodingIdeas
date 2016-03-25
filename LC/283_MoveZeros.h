//
//  283_MoveZeros.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/17/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _83_MoveZeros_h
#define _83_MoveZeros_h
/*
 
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 
 Note:
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        int nz = -1; //position of non-zero
        int i = 0;
        while(i<nums.size()){
            if(nums[i])
                swap(nums[++nz], nums[i]);
            i++;
        }
    }
};

#endif /* _83_MoveZeros_h */
