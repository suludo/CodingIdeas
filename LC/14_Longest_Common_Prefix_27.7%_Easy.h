/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        if(strs.size()==0) return ret;
        
        for(int i=0;; i++){
            char c; // = '\0';
            for(int j=0; j<strs.size(); j++){
                if(i>=strs[j].size()) return ret;
                if(j==0) c= strs[j][i];
                else if(strs[j][i] != c) return ret;
            }
            ret+=c;
        }
    }
};