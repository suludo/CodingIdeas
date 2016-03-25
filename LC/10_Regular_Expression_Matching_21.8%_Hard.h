/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
class Solution {
public:
    //copied from 
    //https://leetcode.com/discuss/51865/my-4ms-dp-solution-another-recursive-version-also-given-72ms
    bool isMatch(string s, string p) {
        int sl = s.size();
        int pl = p.size();
        if(pl==0) return sl==0;

        bool mp[sl+1][pl+1];
        mp[0][0] = true;
        mp[0][1] = false;
        int i=0, j=0;
        for(i=2; i<=pl; ++i)
            mp[0][i] = p[i-1]=='*' ? mp[0][i-2] : false;
        
        for(i=1; i<=sl; ++i)
            for(j=1, mp[i][0]=false; j<=pl; ++j)
                if(p[j-1]=='*') mp[i][j] = j>1 && (mp[i][j-2] || (mp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.')));
                else mp[i][j] = mp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
        
        return mp[sl][pl];
    }
};

class Solution {
public:

    bool isMatch(const char *s, const char *p) {
        
        if(*p=='\0') return *s=='\0';
        
        if(*(p+1)!='*')
            return (*p==*s || (*p=='.' && *s)) && isMatch(s+1, p+1);
        
        while(*p==*s || (*p=='.' && *s)){
            if(isMatch(s,p+2)) return true;
            s++;
        }
        return isMatch(s,p+2);
    }
    bool isMatch(string s, string p) {
        return isMatch (s.c_str(), p.c_str());
    }
};