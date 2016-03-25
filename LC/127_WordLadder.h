//
//  127_WordLadder.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/21/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _27_WordLadder_h
#define _27_WordLadder_h


class Solution {
public:
    bool helper(unordered_set<string>& sw, unordered_set<string>& ew, unordered_set<string>& dict, bool flip, unordered_map<string, vector<string>> dir, int& step){
        flip = !flip;
        if(sw.empty())
            return false;
        if(sw.size()>ew.size())
            return helper(ew, sw, dict, flip, dir, step);
        
        for(string s:sw)
            dict.erase(s);
        for(string s:ew)
            dict.erase(s);
        
        unordered_set<string> layer;
        bool found = false;
        ++step;
        
        for(string s:sw){
            for(int i=0; i<s.size(); ++i){
                string orig = s;
                for(char c ='a'; c<='z'; ++c){
                    //if(c==orig[i])
                    //    continue;
                    s[i] = c;
                    if(ew.find(s) != ew.end()){
                        found = true;
                        return found;
                        // if(flip)
                        //     dir[s].push_back(orig);
                        // else
                        //     dir[orig].push_back(s);
                    }
                    else if(!found && dict.find(s) != dict.end()){
                        layer.insert(s);
                        // if(flip)
                        //     dir[s].push_back(orig);
                        // else
                        //     dir[orig].push_back(s);
                    }
                }
                s = orig;
            }
        }
        return found || helper(ew, layer, dict, flip, dir, step);
    }
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> sw, ew;
        unordered_map<string, vector<string>> mp;
        sw.insert(beginWord);
        ew.insert(endWord);
        int ret = 1;
        if(helper(sw, ew, wordList, false, mp, ret))
            return ret;
        return 0;
    }
};


#endif /* _27_WordLadder_h */
