//
//  139+WordBreak.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _39_WordBreak_h
#define _39_WordBreak_h



class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) return false;
        vector<bool> m(s.size(), false);
        
        for(int j=0; j<s.size(); j++){
            string a = s.substr(0,j+1);
            m[j] = dict.find(a)!=dict.end();
            if(!m[j])
                for(int k=0; k<j; k++){
                    //string f = s.substr(0, k+1);
                    string ss = s.substr(k+1,j-k);
                    m[j] = (m[k] && dict.count(ss)>0);
                    if(m[j]) break;
                }
        }
        return m[s.size()-1];
    }
};


#endif /* _39_WordBreak_h */
