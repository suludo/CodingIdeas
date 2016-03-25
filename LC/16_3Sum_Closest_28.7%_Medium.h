/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        sort(num.begin(), num.end());
        int res;
        if(num.size()<3) return res;
        res = num[0]+num[1]+num[2];
        for(int i=0; i<num.size()-2; i++){
            if(i>0 && num[i]==num[i-1]) continue;
            int start= i+1;
            int end = num.size()-1;

            while(start<end){
                int sum = (num[i]+num[start]+num[end]);
                if(sum==target) return target;
                if(abs(sum-target)<abs(res-target)) res = sum;
                if(sum<target)
                    start++;
                else
                    end--;

            }
        }
        return res;
    }
};