//
//  191_NumberOf1Bits.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _91_NumberOf1Bits_h
#define _91_NumberOf1Bits_h



// pay attn to the use of !!

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for(int i=0; i<32; i++)
            ret += !!(n&(1<<i));
        return ret;
    }
};


#endif /* _91_NumberOf1Bits_h */
