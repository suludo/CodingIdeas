//
//  121_BestTimeToBuyAndSellStock.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _21_BestTimeToBuyAndSellStock_h
#define _21_BestTimeToBuyAndSellStock_h

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1) return 0;
        
        int lowest = prices[0];
        int res = 0;
        
        for(int i=0; i<prices.size(); i++){
            lowest = min(lowest, prices[i]);
            res = max(res, prices[i]-lowest);
        }
        return res;
    }
};


#endif /* _21_BestTimeToBuyAndSellStock_h */
