
//pay attn p2 is initialized to 1
// and the first letter cannot be '0'
//as    A -  Z
//w.r.t 1  -  26
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        
        int p1 = 1, p2 = 1;
        int p = p1;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='0') p = 0;
            else p = p1;
            if(s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<='6'))
                p += p2;

            p2 = p1;
            p1 = p;
        }
        return p;
    }
};


//  p2  p1   p
//      0    1    2    3    4    5    6 ...
//    s[0] s[1] s[2]  s[3] s[4] s[5] s[6]