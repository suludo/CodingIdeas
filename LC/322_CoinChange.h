//
//  322_CoinChange.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _22_CoinChange_h
#define _22_CoinChange_h

class Solution {
public:
    // modified from UBER prep notes
    int coinChange(vector<int>& values, int change) {
        if(change<=0) return 0;
        //sort(values.begin(), values.end());
        vector<int> dp(change+1); //number of minimum coins used for amount i
        
        for(int i=1; i<=change; i++){
            dp[i] = -1;
            for(int j=0; j<values.size(); j++){
                if(values[j]>i) continue;
                int prev = dp[i-values[j]];
                //either current min #coins for change value i is not found
                // or found a smaller #combinations
                if(prev!=-1 && (dp[i]==-1 || prev+1<dp[i]))
                    dp[i] = prev+1;
            }
        }
        return dp[change];
    }
};

#endif /* _22_CoinChange_h */
