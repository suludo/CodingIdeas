/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Subscribe to see which companies asked this question

Show Tags

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty() && s2.empty() && s3.empty()) return true;
        if(s1.size()+s2.size()-s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool>> m(n1+1, vector<bool>(n2+1,false));
        m[0][0] = true;
        for(int i=1; i<=n1;i++)
            m[i][0] = (s3.substr(0, i)==s1.substr(0,i));
        for(int j=1; j<=n2; j++)
            m[0][j] = (s3.substr(0,j)==s2.substr(0,j));
            
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                m[i][j] = (m[i][j-1] && (s2[j-1]==s3[i+j-1]) || (m[i-1][j] && s1[i-1]==s3[i+j-1]));
            }
        }

        return m[n1][n2];
        
    }
};