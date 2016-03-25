/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/
class Solution {
public:
    string minWindow(string S, string T) {
        //map<char, int> total;
        //map<char, int> count; //
        
        int total[256]={0};
        int count[256]={0};
        int wc = 0; //word total count
        int start=0;
        int end = 0;
        string ret = "";
        int minLen = INT_MAX;
        for(int i=0; i<T.size(); i++){
            //if(total.find(T[i])==total.end())
            //    count[T[i]] = 0;
            total[T[i]]++;
        }
        
        for(; end<S.size(); end++){
            if(total[S[end]] == 0) continue;
            
            if(count[S[end]]<total[S[end]])
                wc++;
            count[S[end]]++;
            
            if(count[S[end]]>=total[S[end]] && wc==T.size()){
                while(start<=end){
                    if(total[S[start]] == 0){start++; continue;}
                    if(count[S[start]]==total[S[start]]){
                        if(end-start+1<minLen){
                            minLen = end-start+1;
                            ret = S.substr(start, end-start+1);
                        }
                        break;
                    }
                    count[S[start]]--;
                    start++;
                }
            }
            
            
        }
        return ret;
    }

};