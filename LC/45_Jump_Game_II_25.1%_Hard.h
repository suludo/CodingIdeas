/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
class Solution {
public:
//REVIEW: https://leetcode.com/discuss/10588/o-n-bfs-solution
    // int jump(vector<int>& A) {
    //     int n = A.size();
    //     if(n<2)return 0;
    //      int level=0,currentMax=0,i=0,nextMax=0;
    
    //      while(currentMax-i>=0){       //nodes count of current level>0
    //          level++;
    //          for(;i<=currentMax;i++){   //traverse current level , and update the max reach of next level
    //             nextMax=max(nextMax,A[i]+i);
    //             if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level 
    //          }
    //          currentMax=nextMax;
    //      }
    //      return 0;
    // }
    
    // int jump(vector<int>& A) {
    //     int n = A.size();
    //     if(n<2) return 0;
    //     int level = 0, curMax = 0, nextMax = 0, i=0;
    //     while(curMax-i>=0){
    //         ++level;
    //         //for(; i<=curMax; i++){
    //         while(i<=curMax){
    //             nextMax = max(nextMax, A[i]+i);
    //             if(nextMax>=n-1) return level;
    //             i++;
    //         }
    //         curMax = nextMax;
    //     }
    //     return 0;
    // }
    
    int jump(vector<int>& A) {
        int n = A.size();
        if(n<2) return 0;
        int i=0, curMax = 0, nextMax=0, step = 0;
        while(i<=curMax){
            step++;
            while(i<=curMax){
                nextMax = max(nextMax, A[i]+i);
                if(nextMax>=n-1) return step;
                i++;
            }
            curMax = nextMax;
        }
        return 0;
    }
};