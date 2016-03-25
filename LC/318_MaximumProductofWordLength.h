//
//  318_MaximumProductofWordLength.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _18_MaximumProductofWordLength_h
#define _18_MaximumProductofWordLength_h


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ret = 0;
        
        unordered_map<int, int> mp; // k: mask, v: max length
        
        for(auto w:words){
            int mask = 0;
            for(int i=0; i<w.size(); i++)
                mask |= 1<<(w[i]-'a');
            mp[mask] = max(mp[mask], (int) w.size());
        }
        
        for(auto a:mp){
            for(auto b:mp){
                if(!(a.first & b.first))
                    ret = max(ret, a.second*b.second);
            }
        }
        return ret;
    }
};

#endif /* _18_MaximumProductofWordLength_h */
