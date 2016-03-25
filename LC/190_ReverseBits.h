//
//  190_ReverseBits.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _90_ReverseBits_h
#define _90_ReverseBits_h


//create a new result to fill in, rather than swap

class Solution {
public:
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i=0; i<16; i++){
            ret |= (n>>i & 1)<<(31-i);
            ret |= (n>>(31-i) & 1)<<i;
        }
        return ret;
    }
};

#endif /* _90_ReverseBits_h */
