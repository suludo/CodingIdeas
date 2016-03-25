//
//  131_PalindromePartitioning.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _31_PalindromePartitioning_h
#define _31_PalindromePartitioning_h



class Solution {
public:
    void dfs(string s, int start, vector< vector<bool> >&mp, vector<string> &path, vector< vector<string> > &res)
    {
        if(start == s.size()){
            if(!path.empty())
                res.push_back(path);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(mp[start][i]){
                path.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, mp, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector< vector<bool> > mp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                mp[j][i] = s[i]==s[j] && (i-j<2 || mp[j+1][i-1]);
            }
        }
        vector<string> path;
        vector< vector<string> > ret;
        dfs(s, 0, mp, path, ret);
        return ret;
    }
};


#endif /* _31_PalindromePartitioning_h */
