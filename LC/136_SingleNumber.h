//
//  136_SingleNumber.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _36_SingleNumber_h
#define _36_SingleNumber_h


class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for(int i=0; i<n; i++)
            ret ^= A[i];
        return ret;
    }
};

#endif /* _36_SingleNumber_h */
