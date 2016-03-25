/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
public:
    bool isValid(int cur, int j, vector<int>& mp){
        for(int i=0; i<cur; i++){
            if(mp[i]==j || (cur-i)==abs(j-mp[i]))
                return false;
        }
        return true;
    }
    void helper(int cur, int n, vector<int> & mp, vector<vector<string>> &res){
        
        if(cur>=n){
            vector<string> elem;
            for(int i=0; i<n; i++){
                string row;
                for(int j=0; j<n; j++){
                    if(j==mp[i]) row+='Q';
                    else row+='.';
                }
                elem.push_back(row);
            }
            res.push_back(elem);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(isValid(cur, i, mp)){
                mp[cur] = i;
                helper(cur+1, n, mp, res);
                mp[cur] = -1;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> mp(n, -1);
        helper(0, n, mp, ret);
        return ret;
    }
};