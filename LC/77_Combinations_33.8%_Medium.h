/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    void helper(int n, int k, int cur, vector<int>& path, vector< vector<int> >& res){

        if(path.size()==k){
          res.push_back(path);
            return;  
        } 
        for(int i=cur; i<=n; i++){

            path.push_back(i);
            helper(n,k,i+1,path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ret;
        helper(n, k, 1, path, ret);
        return ret;
    }
};