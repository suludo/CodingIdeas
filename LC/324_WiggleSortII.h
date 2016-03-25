//
//  324_WiggleSortII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _24_WiggleSortII_h
#define _24_WiggleSortII_h


class Solution {
public:
    //TO BE REVIEWED
    //https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing
    //FIRST FIND MEDIAN, THEN PARTITION THE ARRAY BY EVERY TWO ELEMENTS IN DESCENDING ORDER
    //THIS WILL GUARATNTEE THE WIGGLE PROPERTY
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        //i : 0 1 2 3 4 5
        //i': 1 3 5 0 2 4
#define A(i) nums[(1+2*(i)) % (n|1)]
        
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};

#endif /* _24_WiggleSortII_h */
