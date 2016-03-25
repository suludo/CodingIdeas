/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    //n: total num of pairs
    //lp: # left parens
    //k: index of # pairs
    void helper(int n, int lp, int k, string path, vector<string>& res){
        // WORKED
        // if(k==n){
        //     if(lp==0){
        //         if(!path.empty()) res.push_back(path);
        //     }
        //     else helper(n, lp-1, k, path+')', res);
        //     return;
        // }
        // helper(n, lp+1, k+1, path+'(', res);
        // if(lp>0) helper(n, lp-1, k, path+')', res);
        if(k==n){
            if(lp==0) res.push_back(path);
            else helper(n, lp-1, k, path+')', res);
            return;
        }
        helper(n, lp+1, k+1, path+'(', res);
        if(lp>0) helper(n, lp-1, k, path+')', res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        helper(n, 0, 0, path, ret);
        return ret;
    }
};