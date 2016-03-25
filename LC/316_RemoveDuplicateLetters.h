//
//  316_RemoveDuplicateLetters.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _16_RemoveDuplicateLetters_h
#define _16_RemoveDuplicateLetters_h


class Solution {
public:
    //https://leetcode.com/discuss/73824/short-16ms-solution-using-stack-which-can-optimized-down-4ms
    string removeDuplicateLetters(string s) {
        int ahead[26] = {};
        bool inResult[26] = {};
        string res = " ";
        for(char ch:s)
            ahead[ch-'a'] ++;
        
        for(int i=0; i<s.size(); i++){
            int cur = s[i]-'a';
            ahead[cur] --;
            if(inResult[cur])
                continue;
            while(s[i]<res.back() && ahead[res.back()-'a']){
                inResult[res.back()-'a'] = false;
                res.pop_back();
            }
            res += s[i];
            inResult[cur] = true;
        }
        return res.substr(1);
    }
};



#endif /* _16_RemoveDuplicateLetters_h */
