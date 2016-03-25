//
//  301_RemoveInvalidParentheses.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/15/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _01_RemoveInvalidParentheses_h
#define _01_RemoveInvalidParentheses_h

/*
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 
 Note: The input string may contain letters other than the parentheses ( and ).
 
 Examples:
 "()())()" -> ["()()()", "(())()"]
 "(a)())()" -> ["(a)()()", "(a())()"]
 ")(" -> [""]
 */
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;



class Solution {
public:
    void helper(string s, int ol, int skl, int skr, string path, unordered_set<string> &res){
        if(s.empty()){
            if(ol==0 && skl==0 && skr==0)
                res.insert(path);
            return;
        }
        if(s[0]=='('){
            if(skl>0) helper(s.substr(1), ol, skl-1, skr, path, res);
            helper(s.substr(1), ol+1, skl, skr, path+'(', res);
        }
        else if(s[0]==')'){
            if(skr>0) helper(s.substr(1), ol, skl, skr-1, path, res);
            if(ol>0) helper(s.substr(1), ol-1, skl, skr, path+')', res);
        }
        else helper(s.substr(1), ol, skl, skr, path+s[0], res);
    }
    vector<string> removeInvalidParentheses(string s) {
        int skl = 0, skr=0, ol = 0;
        for(auto c:s){
            if(c=='(') skl++;
            else if(c==')')
                if(skl>0) skl--;
                else skr++;
        }
        string path;
        unordered_set<string> ret;
        helper(s, ol, skl, skr, path, ret);
        return vector<string> (ret.begin(), ret.end());
    }
};

void test(){
    Solution s;
    string ss = ")(";//"()())()";//"(a)())()";
    vector<string> res = s.removeInvalidParentheses(ss);
    for(auto p : res)
        cout<<p<<endl;
}
#endif /* _01_RemoveInvalidParentheses_h */
