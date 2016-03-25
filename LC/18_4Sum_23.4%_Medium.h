/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

//https://leetcode.com/discuss/87769/implementation-carefully-pruning-accelerates-from-100ms   for pruning

//check how the pruning works
// and two way picking at the while loop
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if(n<4) return ret;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1; j<n-2; ++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left = j+1, right = n-1;
                while(left<right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target)
                        left++;
                    else if(sum>target)
                        right--;
                    else{
                        vector<int> elem({nums[i], nums[j], nums[left++], nums[right--]});
                        ret.push_back(elem);
                        while(left<right && nums[left]==nums[left-1])   left++;
                        while(right>left && nums[right+1]==nums[right]) right--;
                    }
                }
            }
        }
        return ret;
    }
};


struct iPair{ //index Pair
    int x;
    int y;
    iPair(int _x, int _y):x(_x), y(_y){};
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > ret;
        int n = nums.size();
        unordered_map<int, vector<iPair>> mp;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]+nums[j]].push_back( iPair(i,j) );
            }
        }
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int sum = target-nums[i]-nums[j];
                if(mp.find(sum) != mp.end()){
                    for(int k=0; k<mp[sum].size(); k++){
                        if(mp[sum][k].x > j){
                            if(!ret.empty() && nums[i]==ret.back()[0] && nums[j]==ret.back()[1] && nums[mp[sum][k].x]==ret.back()[2] && nums[mp[sum][k].y]==ret.back()[3]){
                                continue;
                            }
                            vector<int> elem = {nums[i],nums[j],nums[ mp[sum][k].x ], nums[ mp[sum][k].y ]};
                            ret.push_back(elem);
                        }
                    }
                }
            }
        }
        return ret;
    }
};