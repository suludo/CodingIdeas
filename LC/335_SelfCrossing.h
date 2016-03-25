//
//  335_SelfCrossing.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/13/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _35_SelfCrossing_h
#define _35_SelfCrossing_h

//https://leetcode.com/problems/self-crossing/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int N = x.size();
        if (N<=3) return false;
        bool out = (x[2]>x[0]); //ever been out loop?
        
        for(int i = 3; i<N; i++){
            cout << i<<endl;
            if(out){
                if(x[i-1]<=x[i-3] && x[i]+x[i-4]>=x[i-2]) return true;
                if(i>4 && x[i]+x[i-4]>=x[i-2] && x[i-5]+x[i-1]>=x[i-3]) return true;
            }
            else{
                if(x[i]>=x[i-2]) return true;
            }
        }
        return false;
    }
};

void test(){
    Solution S;
}

#endif /* _35_SelfCrossing_h */
