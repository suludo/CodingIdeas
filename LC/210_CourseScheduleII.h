//
//  210_CourseScheduleII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _10_CourseScheduleII_h
#define _10_CourseScheduleII_h

class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> g(numCourses);
        vector<int> d(numCourses);
        vector<int> ret;
        
        for(int i=0; i<prerequisites.size(); i++){
            if(g[prerequisites[i].second].find(prerequisites[i].first) == g[prerequisites[i].second].end()){
                g[prerequisites[i].second].insert(prerequisites[i].first);
                d[prerequisites[i].first]++;
            }
        }
        
        for(int i=0; i<numCourses; i++){ //update every edge of the vertex each time
            int j=0;
            while(j<numCourses && d[j]!=0)
                j++;
            //while still continue searching the i'th course, (i<numCourse)
            //there is no course with 0 in-bound connection,
            //indicating the cycle in the graph
            if(j==numCourses){
                ret.clear();
                return ret;
            }
            d[j]=-1;
            ret.push_back(j);
            for(auto it=g[j].begin(); it!=g[j].end(); it++)
                d[*it]--;
        }
        return ret;
    }
};


#endif /* _10_CourseScheduleII_h */
