/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        stringstream ss(path);
        string s, ret;
        while(getline(ss, s, '/')){
            if(s == "" || s==".") continue;
            if(s == ".."){
                if(!stk.empty())
                    stk.pop_back();
            }
            else
                stk.push_back(s);
        }
        for(auto it : stk)
            ret += "/"+ it;
        return ret.empty() ? "/":ret;
        
    }
};