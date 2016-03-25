//
//  132_PalindromePartitioningII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _32_PalindromePartitioningII_h
#define _32_PalindromePartitioningII_h



//dual DP
//took more than one hour to get the gist
//consider this, split string[i,n] into [i,j] and [j+1,n]
//consider all the conditions when [j+1,n] is palindrome
//this way the prior string which we already computed the minimum cut can be added to form further minimum cut
//*lemma* is a minimum cut must have a j exists that makes [j+1,n] a palindrome
//so one map to store the palindrome mode, the other map stores the current status of minimum cut
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n<=1) return 0;
        vector< vector<bool> >mp(n, vector<bool>(n, false));
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            dp[i] = i;  // maximum value, #cuts
            for(int j=i; j>=0; j--){
                if(s[j]==s[i] && (i-j<2 || mp[j+1][i-1])){
                    mp[j][i] = true;
                    if(j==0) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        return dp.back();
    }
};

#endif /* _32_PalindromePartitioningII_h */
