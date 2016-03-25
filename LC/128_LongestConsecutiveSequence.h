//
//  128_LongestConsecutiveSequence.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _28_LongestConsecutiveSequence_h
#define _28_LongestConsecutiveSequence_h


/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 
 Your algorithm should run in O(n) complexity.*/


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        
        int maxLen = 0;
        int size = num.size();
        
        unordered_map<int, bool> visited;
        for(int i=0; i<size; i++)
            visited[num[i]] = false;
        
        for(int i=0; i<size; i++){
            if(visited[num[i]]) continue;
            int len = 1;
            int index = num[i]+1;
            while(visited.count(index) && !visited[index])
            {
                visited[index] = true;
                index++;
                len++;
            }
            index = num[i]-1;
            while(visited.count(index) && !visited[index])
            {
                visited[index] = true;
                index--;
                len++;
            }
            maxLen = max(maxLen, len);
            visited[num[i]] = true;
        }
        return maxLen;
    }
};
#endif /* _28_LongestConsecutiveSequence_h */
