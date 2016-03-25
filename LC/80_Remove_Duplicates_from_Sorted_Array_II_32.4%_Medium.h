/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //two pointers
        int j = -1;
        int i = 0;
        int cnt = 1;
        
        while(i<nums.size()){
            if(i==0 || nums[i]!=nums[i-1]){
                nums[++j] = nums[i];
                cnt = 1;
            }
            else if(cnt<2){
                cnt++;
                nums[++j] = nums[i];
            }
            i++;
        }
        return j+1;
    }
};