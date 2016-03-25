//
//  264_UglyNumberII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _64_UglyNumberII_h
#define _64_UglyNumberII_h



// ugly sequence * 2
// ............. * 3
// ............. * 5
class Solution {
public:
    // refer to http://www.geeksforgeeks.org/ugly-numbers/
    int nthUglyNumber(int n) {
        if(n==0) return 0;
        vector< int > dp(n,1);
        int i2=0, i5=0, i3=0;
        for(int i=1; i<n; i++){
            int elem = min(dp[i2]*2, min(dp[i3]*3, dp[i5]*5));
            if(elem == dp[i2]*2) i2++;
            if(elem == dp[i3]*3) i3++;
            if(elem == dp[i5]*5) i5++;
            dp[i] = elem;
        }
        return dp.back();
    }
};

#endif /* _64_UglyNumberII_h */
