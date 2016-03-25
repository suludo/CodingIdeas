//
//  189_RotateArray.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _89_RotateArray_h
#define _89_RotateArray_h


class Solution {
public:
    void helper(vector<int>& nums, int s, int e){
        while(s<e)
            swap(nums[s++],nums[e--]);
    }
    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        if(k>nums.size()) k %= nums.size();
        helper(nums, 0, nums.size()-k-1);
        helper(nums, nums.size()-k, nums.size()-1);
        helper(nums, 0, nums.size()-1);
    }
    
    
    void rotate(int nums[], int n, int k) {
        if(n<=1) return;
        k%=n;
        if(k==0) return;
        
        int i=n-k;
        int cur = 0;
        while(i<n)
            swap(nums[i++], nums[cur++]);
        
        rotate(nums+k, n-k, k);
    }
};


#endif /* _89_RotateArray_h */
