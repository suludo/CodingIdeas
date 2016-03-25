//
//  172_FactorialtrailingZeros.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _72_FactorialtrailingZeros_h
#define _72_FactorialtrailingZeros_h


class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n>0)
            ret += (n/=5);
        return ret;
    }
};
#endif /* _72_FactorialtrailingZeros_h */
