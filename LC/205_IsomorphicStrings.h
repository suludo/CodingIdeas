//
//  205_IsomorphicStrings.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/16/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _05_IsomorphicStrings_h
#define _05_IsomorphicStrings_h

/*Given two strings s and t, determine if they are isomorphic.
 
 Two strings are isomorphic if the characters in s can be replaced to get t.
 
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 
 For example,
 Given "egg", "add", return true.
 
 Given "foo", "bar", return false.
 
 Given "paper", "title", return true.
 */

// pay attn to the initialization to 0,
//while store the index as i+1
//so that both keyvalue -> 0 should be both not found before
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int mp1[256] = {0};
        int mp2[256] = {0};
        for(int i=0; i<s.size(); i++){
            if(mp1[s[i]] != mp2[t[i]])
                return false;
            mp1[s[i]] = mp2[t[i]] = i+1;
        }
        return true;
    }
};

#endif /* _05_IsomorphicStrings_h */
