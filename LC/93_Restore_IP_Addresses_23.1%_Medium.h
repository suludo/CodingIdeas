/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:
    void helper(string s, int step, string &path, vector<string> & res){
        if(s.size()<4-step || s.size()>3*(4-step))
            return;
        if(step==4 && s.empty()){
            res.push_back(path);
            return;
        }
        for(int i=0; i<min((int)s.size(), 3); ++i){
            string ss = s.substr(0, i+1);
            int val = stoi(ss);
            if((ss[0]=='0'&&i>0)||val>255)
                continue;
            string tmp = path;
            if(!path.empty())
                path += '.';
            path+=ss;
            helper(s.substr(i+1), step+1, path, res);
            path=tmp;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string path;
        helper(s, 0, path, ret);
        return ret;
    }
};