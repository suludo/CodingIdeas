//
//  309_BestTimeToBuyAndSellStockWithCooldown.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _09_BestTimeToBuyAndSellStockWithCooldown_h
#define _09_BestTimeToBuyAndSellStockWithCooldown_h

class Solution {
public:
    //https://leetcode.com/discuss/71354/share-my-thinking-process
    //b[i] = OVERALL max profit end with buy at i
    //s[i] = OVERALL ... ................sell at i
    //r[i] = ............................rest at i
    //buy after rest, sell after buy
    //b[i] = max(r[i-1] - price, b[i-1])
    //s[i] = max(b[i-1] + price, s[i-1])
    //r[i] = max(b[i-1],  s[i-1], r[i-1])
    //b[i]<=r[i]<=s[i]  =>  r[i] = s[i-1]
    //=>
    //b[i] = max(s[i-2] - price, b[i-1])
    //s[i] = max(b[i-1] + price, s[i-1])
    //return si
    int maxProfit(vector<int>& prices) {
        long b, pb, s, ps;
        b = LONG_MIN;
        pb = 0;
        s = 0;
        ps = 0;
        
        for(int i=0; i<prices.size(); i++){
            pb = b;
            b = max(ps - prices[i], b);
            ps = s;
            s = max(pb + prices[i], s);
        }
        return s;
    }
};


#endif /* _09_BestTimeToBuyAndSellStockWithCooldown_h */
