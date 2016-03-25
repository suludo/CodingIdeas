//
//  126_WordLadderII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _26_WordLadderII_h
#define _26_WordLadderII_h


/*
 Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
 
 Only one letter can be changed at a time
 Each intermediate word must exist in the word list
 For example,
 
 Given:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 Return
 [
 ["hit","hot","dot","dog","cog"],
 ["hit","hot","lot","log","cog"]
 ]
 */
class Solution {
public:
    
    bool helper(unordered_set<string>& startLayer, unordered_set<string>& endLayer, unordered_map<string, vector<string>>& edges, unordered_set<string> &dict, bool flip){
        flip = !flip;
        if(startLayer.empty()) return false;
        if(startLayer.size()>endLayer.size())
            return helper(endLayer, startLayer, edges, dict, flip);
        
        for(auto s:startLayer)
            dict.erase(s);
        for(auto s:endLayer)
            dict.erase(s);
        
        unordered_set<string> midLayer;
        bool found = false;
        for(auto s:startLayer){
            int len = s.size();
            //bool found = false;
            string orig = s;
            for(int i=0; i<len; i++){
                char letter = s[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    s[i] = ch;
                    if(endLayer.find(s) != endLayer.end()){
                        found = true;
                        flip ? edges[s].push_back(orig) : edges[orig].push_back(s);
                    }
                    // if found, don't bother to find the midLayer, as it will terminate after this loop upon the shortest path found
                    else if(!found && dict.find(s) != dict.end()){
                        midLayer.insert(s);
                        flip ? edges[s].push_back(orig) : edges[orig].push_back(s);
                    }
                    
                }
                s[i] = letter;
            }
        }
        return found || helper(endLayer, midLayer, edges, dict, flip);
    }
    
    void genLadder(string start, string end, unordered_map< string, vector<string> >& edges, vector<string>&path, vector< vector<string> >& res){
        if(start.empty()) return;
        path.push_back(start);
        if(start == end){
            //path.push_back(start);
            if(path.empty()==false) res.push_back(path);
            //path.pop_back();
            return;
        }
        for(auto s : edges[start]){
            //path.push_back(start);
            genLadder(s, end, edges, path, res);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector< vector<string> > ret;
        unordered_set<string> s, e;
        unordered_map<string, vector<string>> edges;
        vector<string> path;
        s.insert(beginWord);
        e.insert(endWord);
        if(helper(s, e, edges, wordList, true))
            genLadder(beginWord, endWord, edges, path, ret);
        return ret;
    }
};
#endif /* _26_WordLadderII_h */
