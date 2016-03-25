//
//  221_MaximalSquare.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _21_MaximalSquare_h
#define _21_MaximalSquare_h


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> dp(r+1,0);
        int ul=0, ret=0;
        for(int j=1; j<=c; j++){
            for(int i=1; i<=r; i++){
                int tmp = dp[i];
                if(matrix[i-1][j-1]=='0') dp[i]=0;
                else dp[i] = 1+min(min(dp[i],dp[i-1]), ul);
                ret = max(ret, dp[i]);
                ul = tmp;
            }
        }
        return ret*ret;
    }
};

#endif /* _21_MaximalSquare_h */
