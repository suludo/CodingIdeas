//
//  214_ShortestPalindrome.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _14_ShortestPalindrome_h
#define _14_ShortestPalindrome_h


class Solution {
public:
    //https://www.ics.uci.edu/~eppstein/161/960227.html
    void KMPOverlap(string s, vector<int> &v){
        if(s.empty()) return;
        int n = s.size();
        v.assign(n, 0);
        //v[0] is 0 because the overlap cannot be the entire string,
        //as v[0] stands for the s.substr(0,1) to compare with entire s.
        for(int i=1; i<n; i++){
            //v is the result of the Suffix of current substr(0,i)
            //compare to the Prefix of the entire string
            int j = v[i-1];
            while(j>0 && s[i]!=s[j])
                j = v[j-1];
            v[i] = j + (s[i]==s[j]);
            //cout<<v[i]<<endl<<endl;
        }
    }
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string ss = s+"#"+rev_s;
        
        vector<int> v;
        KMPOverlap(ss, v);
        
        
        return rev_s.substr(0, s.size()-v.back())+s;
    }
};

#endif /* _14_ShortestPalindrome_h */
