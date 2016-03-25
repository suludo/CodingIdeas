//
//  213_HouseRobberII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _13_HouseRobberII_h
#define _13_HouseRobberII_h



class Solution {
public:
    int helper(vector<int>&nums, int start, int end){
        int len = end-start+1;
        vector<int> dp(len, 0);
        for(int i=start; i<=end; i++)
            dp[i-start] = nums[i];
        
        for(int i=1; i<len; i++){
            if(i==1)
                dp[i]=max(nums[start],nums[start+1]);
            else
                dp[i] = max(dp[i-1], dp[i-2]+nums[start+i]);
        }
        
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        
        return max( helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1) );
    }
};


#endif /* _13_HouseRobberII_h */
