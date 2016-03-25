/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, n = nums.size();
        unordered_map<int, int> m;
        vector<int> ret;

        for (i = 0; i < n; ++i)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                ret.push_back(m[target - nums[i]]);
                ret.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }

        return ret;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mp;  //value - indices
        vector<int> ret;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]].push_back(i);
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i])!=mp.end()){
                if(target-nums[i]==nums[i]){
                    if(mp[nums[i]].size()>=2){
                        ret.push_back(mp[nums[i]][0]);
                        ret.push_back(mp[nums[i]][1]);
                        break;
                    }
                }
                else{
                    ret.push_back(mp[nums[i]][0]);
                    ret.push_back(mp[target-nums[i]][0]);
                    break;
                }
            }
        }
        return ret;
    }
};