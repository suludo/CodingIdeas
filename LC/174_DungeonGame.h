//
//  174_DungeonGame.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _74_DungeonGame_h
#define _74_DungeonGame_h


class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.empty()) return 0;
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<int> arr(c, 0);
        
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                //tmp is the minimum requirement of #blood
                //in the previous column and row (to the right, to the bottom
                int64_t tmp = LLONG_MAX;
                if(i==(r-1))
                    if(j==(c-1)){
                        tmp = dungeon[i][j]>=0 ? 1:(1-dungeon[i][j]);
                        arr[j] = tmp;
                        continue;
                    }
                    else
                        tmp = arr[j+1];
                    else if(j==(c-1))
                        tmp = arr[j];
                    else
                        tmp = min(arr[j], arr[j+1]);
                
                //if(dungeon[i][j]>=0)
                //    arr[j] = (tmp-dungeon[i][j]>0) ? (tmp-dungeon[i][j]):1;
                //else
                //    arr[j] = tmp-dungeon[i][j];
                
                if(tmp-dungeon[i][j]>0)
                    arr[j] = tmp-dungeon[i][j];
                else
                    arr[j] = 1;
            }
        }
        return arr[0];
    }
};

#endif /* _74_DungeonGame_h */
