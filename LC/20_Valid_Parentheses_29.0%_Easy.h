/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.empty() || s.size()%2) return false;
        stack<char> st;
        //st.push(s[0]);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i] == '{'){
                st.push(s[i]);
                continue;
            }
            if(st.empty()) return false;
            char prev = st.top();
            if(s[i]==')' && prev != '(')
                return false;
            if(s[i]==']' && prev != '[')
                return false;
            if(s[i]=='}' && prev != '{')
                return false;
            
            if(!st.empty()) st.pop();
        }
        return st.empty();
    }
};