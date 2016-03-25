/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    //DP
    // string longestPalindrome(string s) {
    //     if(s.size()<=1) return s;
    //     int n = s.size();
    //     //vector<vector<bool>> mp(n, vector<bool>(n,false));
    //     bool mp[1000][1000] = {false};
    //     int start = 0;
    //     int end = 0;
    //     for(int j=0; j<n; j++){
    //         for(int i=0;i<=j;i++){
                
    //             mp[i][j] = s[i]==s[j] && (j-i<2 || mp[i+1][j-1]);
                    
    //             if(mp[i][j] && (j-i+1)>(end-start+1)){
    //                 start = i;
    //                 end = j;
    //             }
    //         }
    //     }
    //     return s.substr(start, end-start+1);
    // }
    //Manacher's Algorithm
	//pay attn, initialization, N = 2*N+1
	//L is the length of palindrome, and string len to both sides of center
	//s[(i+l[i]+1)/2]==s[(i-l[i]-1)/2] bear in mind, s does not extend, so this index is used to retrieve the actual char
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        n = 2*n+1;
        vector<int> l(n);
        int c = 1, r = 2;
        l[1] = 1;
        int maxPos = -1, maxLen = -1;
        for(int i=2; i<n; i++){
            int iLeft = 2*c-i;
            l[i] = min(l[iLeft], r-i);
            while(i-l[i]-1>=0 && i+l[i]+1<n && ((i+l[i]+1)%2==0 || s[(i+l[i]+1)/2]==s[(i-l[i]-1)/2]))
                l[i]++;
            if(l[i]>maxLen){
                maxPos = i;
                maxLen = l[i];
            }
            if(i+l[i]>r){
                c = i;
                r = i+l[i];
            }
        }
        return s.substr((maxPos-maxLen)/2, maxLen);
    }
};