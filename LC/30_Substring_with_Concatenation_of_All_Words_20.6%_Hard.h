/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        unsigned long len = L[0].size()*L.size();
        if(S.empty() || L.empty() || S.size()<len) return ret;
        unordered_map<string,int> mp;
        unordered_map<string,int> tmp;
        for(int i=0; i<L.size(); i++)
            mp[L[i]] ++;
        unsigned long wlen = L[0].size();
        for(int i=0; i<=S.size()-len; i++){
            int j = i;
            tmp.clear();
            while(j<i+len){
                string s = S.substr(j, wlen);
                if(mp.find(s)==mp.end())
                    break;
                else{
                    //learnt that when using s that does not exist in tmp, it will return a int equal to 0
                    //if(tmp.find(s)==tmp.end())
                    //    tmp[s] = 1;
                    //else
                    tmp[s]++;
                    if(tmp[s]>mp[s])
                        break;
                }
                j+=wlen;
            }
            if(j==i+len){
                ret.push_back(i);
                //i = j-1;
            }
        }
        return ret;
    }
};