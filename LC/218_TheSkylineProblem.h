//
//  218_TheSkylineProblem.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _18_TheSkylineProblem_h
#define _18_TheSkylineProblem_h
/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

*/

class Solution {
public:
    vector<pair<int, int>> dnc(vector<vector<int>>& buildings, int start, int end){
        vector<pair<int, int>> ret;
        if(start>end) return ret;
        if(start==end){
            ret.push_back(make_pair(buildings[start][0],buildings[start][2]));
            ret.push_back(make_pair(buildings[start][1],0));
            return ret;
        }
        int mid = start + (end-start)/2;
        vector<pair<int, int>> first = dnc(buildings, start, mid);
        vector<pair<int, int>> second = dnc(buildings, mid+1, end);
        int i=0, j=0;
        //previous height of two sub sequence
        int hi = -1, hj = -1;
        int x = 0, h = -1;
        while(i<first.size() && j<second.size()){
            //focus on the simplest case,
            //what if first and second both contains results from one building?
            if(first[i].first < second[j].first){
                x = first[i].first;
                hi = first[i].second;
                i++;
            }
            else if(first[i].first > second[j].first){
                x = second[j].first;
                hj = second[j].second;
                j++;
            }
            else{
                x = first[i].first;
                hi = first[i].second;
                hj = second[j].second;
                i++;
                j++;
            }
            h = max(hi, hj);
            if(ret.empty() || ret.back().second != h)
                ret.push_back(make_pair(x,h));
        }
        while(i<first.size()) ret.push_back(first[i++]);
        while(j<second.size()) ret.push_back(second[j++]);
        return ret;
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        return dnc(buildings, 0, buildings.size()-1);
    }
};

#endif /* _18_TheSkylineProblem_h */
