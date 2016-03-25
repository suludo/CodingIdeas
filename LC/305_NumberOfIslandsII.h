//
//  305_NumberOfIslandsII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/14/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _05_NumberOfIslandsII_h
#define _05_NumberOfIslandsII_h
/*
http://www.cnblogs.com/jcliBlogger/p/4965051.html
https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
Problem Description:

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

This problem requires a classic data structure called UnionFind. Take some efforts to learn it at first, like using this Princeton's notes offered by peisi. This note is very nicely written. Take some patinece to read through it and you will get a tool that is also helpful in the future :-)

The C++ code is as follows, taking peisi's Java code as an example.
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class UnionFind2D{
    int r, c, ni; //ni: number of islands
    vector<int> parent, sz; //parent, size of island of this root node
public:
    UnionFind2D(int m, int n):r(m),c(n),ni(0){
        parent.assign(m*n, -1);
        sz.assign(m*n, 1);
    }
    int getNumIslands(){return ni;}
    //get index in 1D
    int index(int x, int y){return x*c+y;}
    //getParent of node
    int getParent(int x, int y){
        if(x<0 || x>=r || y<0 || y>=c) return -1;
        return parent[ index(x,y) ];
    }
    int add(int x, int y){
        int i = index(x, y);
        if(parent[i]>=0) return parent[i];
        parent[i] = i;
        sz[i] = 1;
        ni ++;
        return i;
    }
    int root(int i){
        while(i!=parent[i]){
            parent[i] = parent[ parent[i] ];
            i = parent[i];
        }
        return i;
    }
    bool find(int p, int q){
        return root(p)==root(q);
    }
    void unite(int p, int q){
        int rp = root(p), rq = root(q);
        if(rp==rq) return;
        //rp , the smaller island is to be added to rq
        if(sz[rp]>sz[rq]) swap(rp,rq);
        parent[rp] = rq; //parent[rq];
        sz[rq] += sz[rp];
        ni --;
    }
    
};


class Solution{
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>> & positions){
        UnionFind2D islands(m, n);
        vector< pair<int, int> > dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<int> res;
        for(auto pos:positions){
            int x = pos.first, y = pos.second;
            int p = islands.add(x,y);
            for(auto& d:dirs){
                int q = islands.getParent(x+d.first, y+d.second);
                if(q>=0 && !islands.find(p, q))
                    islands.unite(p, q);
            }
            res.push_back(islands.getNumIslands());
        }
        return res;
    }
};



void test(){

    vector<pair<int, int>> p = {{0,0},{0,1},{1,2},{2,1}};
    Solution s;
    vector<int> res = s.numIslands2(3, 3, p);
    for(auto r:res)
        cout<< r<< " ";
    cout<<endl;

}































#endif /* _05_NumberOfIslandsII_h */
