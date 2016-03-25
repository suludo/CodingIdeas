//
//  229_MajorityElementsII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _29_MajorityElementsII_h
#define _29_MajorityElementsII_h


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int c1=0, c2=0;
        int len = nums.size();
        int a, b;
        
        for(int i=0; i<len; i++){
            if(c1==0 || nums[i]==a){
                c1++;
                a = nums[i];
            }
            else if(c2==0 || nums[i]==b){
                c2++;
                b=nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(int i=0; i<len; i++){
            if(nums[i]==a) c1++;
            else if(nums[i]==b) c2++;
        }
        vector<int> ret;
        if(c1>len/3) ret.push_back(a);
        if(c2>len/3) ret.push_back(b);
        return ret;
    }
};


#endif /* _29_MajorityElementsII_h */
