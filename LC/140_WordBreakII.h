//
//  140_WordBreakII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _40_WordBreakII_h
#define _40_WordBreakII_h

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
    unordered_map<string, vector<string>> m;
    
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.find(s) != m.end()) return m[s];
        vector<string> res;
        if(dict.find(s) != dict.end()) res.push_back(s);
        for(int i=1; i<s.size(); i++){
            string tail = s.substr(i);
            if(dict.find(tail) != dict.end()){
                string head = s.substr(0,i);
                vector<string> comb = combine(tail, wordBreak(head, dict));
                res.insert(res.end(), comb.begin(), comb.end());
            }
        }
        m[s] = res;
        return res;
        // if(m.count(s)) return m[s]; //take from memory
        // vector<string> result;
        // if(dict.count(s)){ //a whole string is a word
        //     result.push_back(s);
        // }
        // for(int i=1;i<s.size();++i){
        //     string word=s.substr(i);
        //     if(dict.count(word)){
        //         string rem=s.substr(0,i);
        //         vector<string> prev=combine(word,wordBreak(rem,dict));
        //         result.insert(result.end(),prev.begin(), prev.end());
        //     }
        // }
        // m[s]=result; //memorize
        // return result;
    }
};




//reverse order also works
class Solution1 {
    unordered_map<string, vector<string>> m;
    
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            //prev[i]+=" "+word;
            prev[i] = word + " " + prev[i];
        }
        return prev;
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(0,i);
            if(dict.count(word)){
                string rem=s.substr(i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};

void test(){
    string b = "okay";
    string a = "youbetitis        " + b;
    cout<<a<<endl;
}

#endif /* _40_WordBreakII_h */
