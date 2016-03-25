//
//  207_CourseSchedule.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _07_CourseSchedule_h
#define _07_CourseSchedule_h


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int>> g(numCourses);
        vector<int> d(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++)
            g[prerequisites[i].second].insert(prerequisites[i].first);
        
        for(int i=0; i<numCourses; i++)
            for(auto it=g[i].begin(); it!=g[i].end(); it++)
                d[*it]++;
        
        for(int i=0; i<numCourses; i++){
            int j=0;
            //pickout the current source node
            while(j<numCourses){
                if(d[j]==0) break;
                j++;
            }
            //either d[j]>0 or d[j]=-1 for all j = 0..n-1
            // i.e. no existing j such that d[j]==0
            if(j==numCourses) return false;
            
            d[j] = -1;
            for(auto it=g[j].begin(); it!=g[j].end(); it++)
                d[*it]--;
        }
        return true;
    }
};

#endif /* _07_CourseSchedule_h */
