//
//  149_MaxPointsOnALine.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _49_MaxPointsOnALine_h
#define _49_MaxPointsOnALine_h

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if(n<=2) return n;
        unordered_map<float, int> mp;
        int res = 0;
        
        for(int i=0; i<n; i++){
            int dup=1;
            mp.clear();
            for(int j=0; j<n; j++){
                if(i!=j){
                    if(points[i].x == points[j].x){
                        if(points[i].y == points[j].y)
                            dup++;
                        // else if(mp.count(9999999)==0)
                        //     mp[9999999] = 1;
                        else
                            mp[9999999] ++;
                    }
                    else{
                        float k = 10000*(points[j].y - points[i].y)/(points[j].x - points[i].x);
                        // if(mp.count(k)==0)
                        //     mp[k] = 1;
                        //else
                        mp[k] ++;
                    }
                }
            }
            //if(mp.empty()) res = max(dup, res);
            //else
            for(unordered_map<float,int>::iterator it = mp.begin(); it!=mp.end(); it++)
                res = max(it->second+dup, res);
            res = max(dup, res);
        }
        return res;
    }
};


#endif /* _49_MaxPointsOnALine_h */
