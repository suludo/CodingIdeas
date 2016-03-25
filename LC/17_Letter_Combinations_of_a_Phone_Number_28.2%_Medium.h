/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    void dfs(string digits, int cur, string s, vector<string>& res, unordered_map<char, string>& dict){
        if(cur>=digits.size()){
            if(!s.empty())
                res.push_back(s);
            return;
        }
        if(dict[digits[cur]].empty())
            return dfs(digits, cur+1, s, res, dict);
            
        for(auto c : dict[digits[cur]])
            dfs(digits, cur+1, s+c, res, dict);
    }
    vector<string> letterCombinations(string digits) {
        string s;
        vector<string> ret;
        unordered_map<char, string> dict;
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        dfs(digits, 0, s, ret, dict);
        return ret;
    }
};