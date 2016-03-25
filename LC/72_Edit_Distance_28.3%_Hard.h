/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> mp(l1+1, vector<int>(l2+1));
        
        for(int i=1; i<=l1; i++)
            mp[i][0] = i;
        for(int i=1; i<=l2;i++)
            mp[0][i] = i;
            
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                int val = min(mp[i-1][j],mp[i][j-1]) + 1;
                
                val = min(val, mp[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0:1));
                
                mp[i][j] = val;
            }
        }
        return mp[l1][l2];
    }
};