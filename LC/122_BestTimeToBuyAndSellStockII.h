//
//  122_BestTimeToBuyAndSellStockII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _22_BestTimeToBuyAndSellStockII_h
#define _22_BestTimeToBuyAndSellStockII_h



class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        int minBar = 0;
        int sum = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1])
                sum += (prices[i]-prices[i-1]);
            //minBar = i;
        }
        return sum;
    }
};
#endif /* _22_BestTimeToBuyAndSellStockII_h */
