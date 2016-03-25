//
//  188_BestTimeToBuyAndSellStockIV.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _88_BestTimeToBuyAndSellStockIV_h
#define _88_BestTimeToBuyAndSellStockIV_h


//pay attn to if k>=half size, then
//it will reach this #transactins when the price comes as / \ / \
//e.g. 1 2 1 2 1 2, bcz if there is more than two increasing in a row, transaction can be merged

//cur_max is monotonically increasing


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k>=prices.size()/2){
            int ret = 0;
            for(int i=1; i<prices.size(); i++){
                if(prices[i]-prices[i-1]>0)
                    ret += (prices[i]-prices[i-1]);
            }
            return ret;
        }
        int mp[2][prices.size()+1];
        memset(mp, 0, 2*(prices.size()+1)*sizeof(int));
        //memset(mp, 0, sizeof(mp));
        
        for(int i=1; i<=k; i++){
            int cur_max = INT_MIN;
            mp[i%2][0]=0;
            for(int j=1; j<=prices.size(); j++){
                mp[i%2][j] = max(mp[(i+1)%2][j], max(mp[i%2][j-1], prices[j-1]+cur_max));
                cur_max = max(cur_max, mp[(i+1)%2][j-1]-prices[j-1]);
            }
        }
        return mp[k%2][prices.size()];
    }
};


#endif /* _88_BestTimeToBuyAndSellStockIV_h */
