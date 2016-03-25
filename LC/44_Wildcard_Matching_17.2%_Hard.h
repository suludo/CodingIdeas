/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
//pay attn , dp solution, how to init and how to deal with p[j]=='*'
class Solution {
public:
    // bool isMatch(string s, string p) {
    //     if(p.empty()) return s.empty();
    //     int i, j, ss, star;
    //     i = j = 0;
    //     ss = star = -1;
        
    //     while(i < s.size()){
    //         if(s[i]==p[j] || p[j]=='?'){
    //             i++; j++;
    //         }
    //         else if(p[j]=='*'){
    //             star = j++;
    //             ss = i;
    //         }
    //         else{
    //             if(ss<0) return false;
    //             i = ++ss;
    //             j = star + 1;
    //         }
    //     }
        
    //     while(j<p.size() && p[j]=='*') j++;
    //     return j==p.size();
    // }
    
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int i=0, j=0;
        int ss= -1, star = -1;
        while(i<s.size()){
            if(s[i]==p[j] || p[j]=='?'){
                i++; j++;
            }
            else if(p[j]=='*'){
                star = j++;
                ss = i;
            }
            else{
                if(ss<0) return false;
                i = ++ss;
                j = star +1;
            }
        }
        while(j<p.size() && p[j]=='*') j++;
        return j==p.size();
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int slen = s.size();
        int plen = p.size();
        vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
        
        for(int j=0; j<=plen; j++){
            if(j==0) dp[0][j] = true;
            else dp[0][j] = p[j-1]=='*' ? dp[0][j-1]:false;
        }
        
        for(int i=1; i<=slen; i++){
            for(int j=1; j<=plen; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
        
        return dp[slen][plen];
    }
};