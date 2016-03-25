//
//  169_MajorityElement.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _69_MajorityElement_h
#define _69_MajorityElement_h



class Solution {
public:
    int majorityElement(vector<int> &num) {
        if(num.empty()) return INT_MIN;
        int cur = num[0];
        int count = 1;
        
        for(int i=1; i<num.size(); i++){
            if(num[i]==cur){
                count++;
            }
            else if(count>0){
                count--;
                if(count==0){
                    cur = num[i];
                    count = 1;
                }
            }
        }
        if(count>0)
            return cur;
        return INT_MIN;
    }
};

class Solution {
public:
    int majorityElement(vector<int> &num) {
        unsigned long len = num.size();
        int ret = 0;
        vector<int> arr(32, 0);
        for(int i=0; i<32; i++){
            for(int j=0; j<num.size(); j++){
                int m = num[j] & (1<<i);
                if(m!=0) arr[i]++;
            }
        }
        for(int i=0; i<32; i++){
            int mask = arr[i]>(len/2) ? 1<<i:0;
            ret |= mask;
        }
        return ret;
    }
};


#endif /* _69_MajorityElement_h */
