//
//  290_WordPattern.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/17/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _90_WordPattern_h
#define _90_WordPattern_h
/*
 Given a pattern and a string str, find if str follows the same pattern.
 
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 
 Examples:
 pattern = "abba", str = "dog cat cat dog" should return true.
 pattern = "abba", str = "dog cat cat fish" should return false.
 pattern = "aaaa", str = "dog cat cat dog" should return false.
 pattern = "abba", str = "dog dog dog dog" should return false.
 Notes:
 You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 */
class Solution {
public:
    string getNext(string s, int &start){
        string ret;
        if(s.empty() || start>=s.size()) return ret;
        int i = start;
        while(i<=s.size()){
            if(i==s.size() || s[i]==' '){
                ret = s.substr(start, i-start);
                start = i==s.size() ? i: i+1;
                break;
            }
            i++;
        }
        return ret;
    }
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> mp;
        unordered_map<string, int> mp1;
        int i = 0;
        int j = 0;
        for(; i<pattern.size(); i++){
            string s = getNext(str, j);
            if(s.empty())
                return false;
            if(mp[pattern[i]] != mp1[s])
                return false;
            //including: not initialized -> both 0's , init to i+1
            //or already has non zero values and equals, update index to the latest
            mp[pattern[i]] = mp1[s] = i+1;
        }
        return j==str.size();
    }
};

#endif /* _90_WordPattern_h */
