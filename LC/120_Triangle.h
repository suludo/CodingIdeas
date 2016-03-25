//
//  120_Triangle.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _20_Triangle_h
#define _20_Triangle_h


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==0) return 0;
        vector<int> mp(n);
        mp[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            for(int j=i; j>=0; j--){
                if(j==i) mp[j] = mp[j-1] + triangle[i][j];
                else if(j==0) mp[j] = mp[j] + triangle[i][j];
                else mp[j] = triangle[i][j] + min(mp[j], mp[j-1]);
            }
        }
        return *min_element(mp.begin(), mp.end());
    }
};

#endif /* _20_Triangle_h */
