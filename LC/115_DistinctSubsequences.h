//
//  115_DistinctSubsequences.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _15_DistinctSubsequences_h
#define _15_DistinctSubsequences_h



class Solution {
public:
    int numDistinct(string s, string t) {
        int T = t.size();
        int S = s.size();
        //if(T>S) return 0;
        //if(T==S) return s==t ? 1:0;
        vector<vector<int>> dp(T+1, vector<int>(S+1, 0));
        
        for(int i=0; i<=S; i++)
            dp[0][i] = 1;
        
        for(int i=1; i<=T; i++){
            for(int j=i; j<=S; j++){
                dp[i][j] = dp[i][j-1] + ( t[i-1]==s[j-1] ? dp[i-1][j-1]:0 );
            }
        }
        return dp[T][S];
    }
};


#endif /* _15_DistinctSubsequences_h */
