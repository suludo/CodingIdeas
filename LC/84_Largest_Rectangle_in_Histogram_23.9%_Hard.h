/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/


class Solution {
public:
    // int largestRectangleArea(vector<int>& height) {
    //     int ret = 0;
    //     height.push_back(0);
    //     stack<int> stk;
    //     int i=0; 
    //     while(i<height.size()){
    //         if(stk.empty() || height[i]>=height[stk.top()])
    //             stk.push(i);
    //         else{
    //             int h = height[stk.top()];
    //             stk.pop();
    //             ret = max(ret, h * (stk.empty() ? i : i-stk.top()-1));
    //             i--;
    //         }
    //         i++;
    //     }
    //     return ret;
    // }
    int largestRectangleArea(vector<int>& height) {
        int ret = 0;
        height.push_back(0);
        stack<int> stk; //index
        int i=0;
        while(i<height.size()){
            if(stk.empty() || height[i]>=height[stk.top()])
                stk.push(i);
            else{
                int tmp = stk.top();
                stk.pop();
                ret = max(ret, height[tmp] * (stk.empty()?i:(i-stk.top()-1)));
                i--;
            }
            i++;
        }
        return ret;
    }
};