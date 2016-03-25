//
//  187_RepeatedDNASequences.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _87_RepeatedDNASequences_h
#define _87_RepeatedDNASequences_h


class Solution {
public:
    int dti(string d){
        int ret = 0;
        if(d.size()!=10) return ret;
        for(int i=d.size()-1; i>=0; i--){
            ret<<=2;
            int mask=0;
            if(d[i]=='A')
                mask = 0;
            else if(d[i]=='C')
                mask = 1;
            else if(d[i]=='G')
                mask = 2;
            else //'T'
                mask = 3;
            ret |= mask;
        }
        return ret;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if(s.size()<10) return ret;
        unordered_map<int, int> mp;
        for(int i=0; i<=s.size()-10; i++){
            string ss = s.substr(i,10);
            int j = dti(ss);
            if(mp.find(j)!=mp.end()){
                if(mp[j]==1)
                    ret.push_back(ss);
                mp[j]++;
            }
            else
                mp[j] = 1;
        }
        return ret;
    }
    
    //only use 20 digits to aoid hash calculation every time
    //use 0xfffff to mask only the right most 20 digits
    //https://leetcode.com/discuss/44689/10-lines-c-code-8-ms-passed
    vector<string> findRepeatedDnaSequences(string s) {
        char  hashMap[1048576] = {0};
        vector<string> ans;
        int len = s.size(),hashNum = 0;
        if (len < 11) return ans;
        for (int i = 0;i < 9;++i)
            hashNum = hashNum << 2 | (s[i] - 'A' + 1) % 5;
        for (int i = 9;i < len;++i)
            if (hashMap[hashNum = (hashNum << 2 | (s[i] - 'A' + 1) % 5) & 0xfffff]++ == 1)
                ans.push_back(s.substr(i-9,10));
        return ans;
    }
};


#endif /* _87_RepeatedDNASequences_h */
