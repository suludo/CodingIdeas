//
//  239_SlidingWindowMaximum.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _39_SlidingWindowMaximum_h
#define _39_SlidingWindowMaximum_h



class Solution {
public:
    //Let D be the dequeue which maintain a pair of information (i, ai). An important property of D that we will maintain is that element in D will always be in sorted order (invariant). We will first start with an empty D, and will insert ai and remove elements from D accordingly as we iterate from the left to the right of array a (which is from i = 0, 1, 2, ..., n).
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ret;
        
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && i-dq.front() >= k)
                dq.pop_front();
//            while(!dq.empty() && nums[dq.back()]< nums[i])   //ALSO WORKS
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};

#endif /* _39_SlidingWindowMaximum_h */
