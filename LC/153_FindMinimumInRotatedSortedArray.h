//
//  153_FindMinimumInRotatedSortedArray.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _53_FindMinimumInRotatedSortedArray_h
#define _53_FindMinimumInRotatedSortedArray_h


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()){
            cout<<"array empty!"<<endl;
            return INT_MIN;
        }
        if(nums.size()==1) return nums[0];
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            if(nums[l]<nums[r]) return nums[l];
            if(nums[l]==nums[r]) r--;
            else{
                int mid = l + (r-l)/2;
                if(nums[mid]<nums[l])
                    r = mid;
                else
                    l = mid +1;
            }
        }
        //return nums[r] or nums[l] does not quite make a difference here
        return nums[r];
    }
};


#endif /* _53_FindMinimumInRotatedSortedArray_h */
