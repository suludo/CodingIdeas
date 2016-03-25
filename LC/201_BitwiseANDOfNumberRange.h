//
//  BitwiseANDOfNumberRange.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef BitwiseANDOfNumberRange_h
#define BitwiseANDOfNumberRange_h


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m>n){
            cout<<"Error: m should not be larger than n!!"<<endl;
            return -1;
        }
        if(m==n) return m;
        int shift = 0;
        while(m!=n){
            m>>=1;
            n>>=1;
            shift ++;
        }
        return m<<shift;
    }
};


#endif /* BitwiseANDOfNumberRange_h */
