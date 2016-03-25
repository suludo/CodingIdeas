//
//  123_BestTimeToBuyAndSellStockIII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _23_BestTimeToBuyAndSellStockIII_h
#define _23_BestTimeToBuyAndSellStockIII_h


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len<2) return 0;
        vector<int> maxLeft(len, 0);
        vector<int> maxRight(len, 0);
        int minBar = 0;
        for(int i=1; i<len; i++){
            if(prices[i]>prices[minBar])
                maxLeft[i] = max(prices[i]-prices[minBar], maxLeft[i-1]);
            else{
                maxLeft[i] = maxLeft[i-1];
                minBar = i;
            }
        }
        
        int maxBar = len-1;
        for(int i=len-2; i>=0; i--){
            if(prices[i]<prices[maxBar])
                maxRight[i] = max(prices[maxBar]-prices[i], maxRight[i+1]);
            else{
                maxRight[i] = maxRight[i+1];
                maxBar = i;
            }
        }
        
        int ret = 0;
        for(int i=0; i<len; i++)
            ret = max(ret, maxLeft[i]+maxRight[i]);
        
        return ret;
    }
};


#endif /* _23_BestTimeToBuyAndSellStockIII_h */
