//
//  179_LargestNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _79_LargestNumber_h
#define _79_LargestNumber_h





class Comp{
public:
    bool operator()(int i, int j) const{
        string s1 = to_string(i);
        string s2 = to_string(j);
        string s12 = s1+s2;
        string s21 = s2+s1;
        //pay attn , should use sort to return a bigger number
        return s12>s21;
    }

};


bool compare(long a, long b){
    int e1=10,e2=10;
    while (e1 <= a)e1*=10;
    while (e2 <= b)e2*=10;
    return a * e2 + b > a + b * e1;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        string ret;
        if(nums.empty()) return ret;
        sort(nums.begin(), nums.end(), compare);
        for(auto n:nums)
            ret += to_string(n);
        return ret[0]=='0' ? "0" : ret;
    }
};

#endif /* _79_LargestNumber_h */
