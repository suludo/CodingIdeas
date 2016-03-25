/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        string ret;
        for(int i=1; i<=n; i++){
            if(i==1)
                ret = "1";
            else{
                int count = 0;
                string next;
                for(int j=0; j<ret.size(); j++){
                    char c = ret[j];
                    ++count;
                    while(j<(ret.size()-1) && ret[j+1]==c){
                        ++count;
                        ++j;
                    }
                    next += ('0'+count);
                    next += c;
                    count = 0;
                }
                ret = next;
            }
        }
        return ret;
    }
};