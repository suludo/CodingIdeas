//
//  ReconstructItinerary.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef ReconstructItinerary_h
#define ReconstructItinerary_h

class Solution {
    //map<int, multiset<int>> mp;
    map<string, multiset<string>> mp;
    vector<string> itinerary;
public:
    
    void dfs(string start){
        while(mp[start].size()){
            string next = *mp[start].begin();
            mp[start].erase(mp[start].begin());
            dfs(next);
        }
        itinerary.push_back(start);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto a : tickets)
            mp[a.first].insert(a.second);
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

#endif /* ReconstructItinerary_h */
