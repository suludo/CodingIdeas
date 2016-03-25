//
//  334_IncreasingTripletSubsequence.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _34_IncreasingTripletSubsequence_h
#define _34_IncreasingTripletSubsequence_h

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            
            auto it = std::lower_bound(v.begin(), v.end(), nums[i]);
            if(it == v.end()){
                v.push_back(nums[i]);
                if(v.size()>=3) return true;
            }
            else
                *it = nums[i];
        }
        return false;
    }
};


#endif /* _34_IncreasingTripletSubsequence_h */
