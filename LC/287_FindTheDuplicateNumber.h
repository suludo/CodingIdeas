//
//  287_FindTheDuplicateNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/17/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _87_FindTheDuplicateNumber_h
#define _87_FindTheDuplicateNumber_h



//same with the looped linked list
//https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n<2) return -1;
    //init as this to ensure the correctness of while
    int s = nums[0], f = nums[nums[0]];
    while(s!=f){
        s = nums[s];
        f = nums[nums[f]];
    }
    f = 0;
    while(f!=s){
        f= nums[f];
        s = nums[s];
    }
    return s;
}


//https://leetcode.com/discuss/89038/o-32-n-solution-using-bit-manipulation-in-10-lines
//bit manipulation
public int findDuplicate(int[] nums) {
    int n = nums.length-1, res = 0;
    for (int p = 0; p < 32; ++ p) {
        int bit = (1 << p), a = 0, b = 0;
        for (int i = 0; i <= n; ++ i) {
            if (/*i > 0 &&*/ (i & bit) > 0) ++a;
            if ((nums[i] & bit) > 0) ++b;
        }
        if (b > a) res += bit;
    }
    return res;
}
#endif /* _87_FindTheDuplicateNumber_h */
