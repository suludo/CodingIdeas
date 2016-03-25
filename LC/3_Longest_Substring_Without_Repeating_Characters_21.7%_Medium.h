/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

//pay attn
// always count the maximum length
//before compare, just check it with the last pointer that's no duplicate with current char
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mp[256];
        memset(mp, -1, 256*sizeof(int));
        int start = 0;
        int ret = 0;
        for(int i=0; i<s.size(); i++){
            if(mp[ s[i] ]>=start)
                start = mp[s[i]]+1;
            mp[s[i]] = i;
            ret = max(ret, i-start+1);
        }
        return ret;
    }
};