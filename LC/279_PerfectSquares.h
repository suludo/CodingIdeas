//
//  279_PerfectSquares.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/17/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _79_PerfectSquares_h
#define _79_PerfectSquares_h


class Solution {
public:
    int numSquares(int n) {
        //int ub = sqrt(n);
        for(int i=0; i*i<=n; i++){
            for(int j=i; i*i+j*j<=n; j++){
                int k = sqrt(n-i*i-j*j);
                if(i*i+j*j+k*k == n)
                    return !!i + !!j + !!k;
            }
        }
        return 4;
    }
};

#endif /* _79_PerfectSquares_h */
