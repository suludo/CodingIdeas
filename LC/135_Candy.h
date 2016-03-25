//
//  135_Candy.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _35_Candy_h
#define _35_Candy_h


class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty()) return 0;
        vector<int> candies(ratings.size(),1);
        
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]) candies[i] = candies[i-1]+1;
        }
        for(int i=ratings.size()-2;i>=0; i--){
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) candies[i]=candies[i+1]+1;
        }
        int total=0;
        for(int i=0; i<candies.size(); i++)
            total += candies[i];
        return total;
    }
};

#endif /* _35_Candy_h */
