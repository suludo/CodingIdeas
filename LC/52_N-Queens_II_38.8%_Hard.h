/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/
class Solution {
public:
    bool isValid(int cur, int j, vector<int>&mp){
        for(int i=0; i<cur; i++)
            if(mp[i]==j || abs(cur-i)==abs(j-mp[i])) return false;
        return true;
    }
    void helper(int cur, int n, vector<int> &mp, int &sum){
        if(cur==n){++sum; return;}
        for(int j=0; j<n; j++){
            if(isValid(cur, j, mp)){
                mp[cur] = j;
                helper(cur+1, n, mp, sum);
                mp[cur] = -1;
            }
        }
    }
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> mp(n, -1);
        helper(0, n, mp, sum);
        return sum;
    }
};