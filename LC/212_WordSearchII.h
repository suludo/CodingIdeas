//
//  212_WordSearchII.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _12_WordSearchII_h
#define _12_WordSearchII_h

#include <vector>
#include <string>
using namespace std;

    class Trie{
    public:
        //Trie* mp[26];
        vector<Trie*> mp;
        bool leaf;
        int idx;
        Trie() {
            mp.assign(26, NULL);
            // for(int i=0; i<26; i++)
            //     mp[i] = NULL;
            leaf = false;
            idx = -1;
        }
    };
class Solution {
public:

    void build(vector<string>& word, Trie* root){
        Trie* tmp = root;
        for(int i=0; i<word.size(); i++){
            for(int j=0; j<word[i].size(); j++){
                int k = word[i][j]-'a';
                if(!root->mp[k])
                    root->mp[k] = new Trie();
                root = root->mp[k];
            }
            root->leaf = true;
            root->idx = i;
            root = tmp;
        }
    }
    
    void check(vector<string>& words, vector<vector<char>>& board, int i, int j, Trie* t, vector<string>& res){
        
        if(res.size() == words.size()) return;
        int nr = board.size();
        int nc = board[0].size();
        //cout<<"check: "<<i<<" "<<j<<" "<<nr<<" "<<nc<<endl;
        if(i<0 || i>=nr || j<0 || j>=nc) return;
        if(board[i][j] == '-') return;
        char tmp = board[i][j];
        int k = board[i][j]-'a';
        if( !t->mp[k] ) return;
        if(t->mp[k]->leaf){
            res.push_back( words[t->mp[k]->idx] );
            t->mp[k]->leaf = false;
        }
        board[i][j] = '-';
        //cout<<"before recursive.."<<endl;
        check(words, board, i+1, j, t->mp[k], res);
        check(words, board, i-1, j, t->mp[k], res);
        check(words, board, i, j+1, t->mp[k], res);
        check(words, board, i, j-1, t->mp[k], res);
        //cout<<"check over..==================="<<endl;
        board[i][j] = tmp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* t = new Trie();
        build(words, t);
        
        if(board.empty() || board[0].empty()) return res;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                //cout<<i<<" "<<j<<endl;
                check(words, board, i, j, t, res);
            }
        }
        return res;
    }
    
    
};

void test(){}

#endif /* _12_WordSearchII_h */
