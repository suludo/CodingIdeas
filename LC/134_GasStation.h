//
//  134_GasStation.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _34_GasStation_h
#define _34_GasStation_h


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        //grasp the point:
        //if i->j cannot guarantee arrival up to j+1
        //then all the i+k up to j cannot arrive j+1
        // because if exists such k, the i->k will be forced to have a negative net gas
        // that is not allowed in reality
        int net = 0;
        int start = 0;
        int netFromStart = 0;
        for(int i=0; i<gas.size(); i++){
            net += (gas[i]-cost[i]);
            netFromStart += (gas[i]-cost[i]);
            if(netFromStart<0){
                start = i+1;
                netFromStart = 0;
            }
        }
        if(net<0) return -1;
        return start;
    }
};

#endif /* _34_GasStation_h */
