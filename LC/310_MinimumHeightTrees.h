//
//  310_MinimumHeightTrees.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _10_MinimumHeightTrees_h
#define _10_MinimumHeightTrees_h

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector< unordered_set<int> > g(n);
        vector<int> deg(n, -1);
        for(int i = 0; i<edges.size(); i++){
            g[edges[i].first].insert(edges[i].second);
            g[edges[i].second].insert(edges[i].first);
        }
        for(int i=0; i<n; i++)
            deg[i] = g[i].size();
        int remain = n;
        while(remain>2){
            vector<int> del;
            for(int i=0; i<deg.size(); i++)
                if(deg[i]==1)
                    del.push_back(i);
            
            for(int i=0; i<del.size(); i++){
                for(auto a:g[ del[i] ])
                    deg[a]--;
                deg[ del[i] ] = -1;
                remain--;
            }
        }
        vector<int> res;
        for(int i=0; i<deg.size(); i++)
            if(deg[i]>=0)
                res.push_back(i);
        return res;
    }
};

#endif /* _10_MinimumHeightTrees_h */
