//
//  216_CombinationSumIII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _16_CombinationSumIII_h
#define _16_CombinationSumIII_h


class Solution {
public:
    void helper(int k, int n, int start, int curSum, vector<int>& path, vector< vector<int> >& res){
        if(curSum>n || path.size()>k) return;
        if(path.size()==k){
            if(curSum == n)
                res.push_back(path);
            return;
        }
        for(int i=start; i<=9; i++){
            path.push_back(i);
            helper(k, n, i+1, curSum+i, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector< vector<int> > ret;
        helper(k,n,1,0,path,ret);
        return ret;
    }
};

#endif /* _16_CombinationSumIII_h */
