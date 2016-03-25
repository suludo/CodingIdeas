/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int cur = 0;
        stack<int> lp; //left parens
        int ret = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                lp.push(i);
            else if(lp.empty())
                cur = i+1;
            else{
                lp.pop();
                if(lp.empty())
                    ret = max(ret, i-cur+1);
                else
                    ret = max(ret, i-lp.top());
            }
        }
        return ret;
    }
};