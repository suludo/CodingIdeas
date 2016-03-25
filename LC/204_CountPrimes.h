//
//  204_CountPrimes.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _04_CountPrimes_h
#define _04_CountPrimes_h


class Solution {
public:
    int countPrimes(int n) {
        bool* mp = new bool[n];
        for(int i=2; i<n; i++)
            mp[i]=true;
        
        for(int i=2; i*i<n; i++){
            if(!mp[i]) continue;
            for(int j=i*i; j<n; j+=i)
                mp[j] = false;
        }
        int ret = 0;
        for(int i=2; i<n; i++)
            if(mp[i]==true)
                ret++;
        return ret;
    }
};

#endif /* _04_CountPrimes_h */
