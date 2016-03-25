//
//  211_AddAndSearchWord-DataStructureDesign.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _11_AddAndSearchWord_DataStructureDesign_h
#define _11_AddAndSearchWord_DataStructureDesign_h

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Node{
public:
    vector<Node*> mp;
    bool leaf;
    Node(){
        mp.assign(26, NULL);
        leaf = false;
    }
};

class Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    
    bool hSearch(string word, Node* n){
        if(!n) return false;
        if(word.empty()) return n->leaf;
        
        char c = word[0];
        int idx = c-'a';
        
        if(c=='.'){
            for(int i=0; i<26; i++)
                if(hSearch(word.substr(1), n->mp[i])) return true;
        }
        else if(idx>=0 && idx<26 && n->mp[idx]){
            if(hSearch(word.substr(1), n->mp[idx])) return true;
        }
            
        return false;
    }
public:
    static Trie& getInstance(){
        static Trie t;
        return t;
    }
    Trie(const Trie&) = delete;
    void operator=(const Trie&) = delete;
    void insert(string word){
        Node* cur = root;
        for(auto c:word){
            int idx = c-'a';
            if(cur->mp[idx]==NULL)
                cur->mp[idx] = new Node();
            cur = cur->mp[idx];
        }
        cur->leaf = true;
    }
    bool search(string word){
        return hSearch(word, root);
        //return false;
    }
    
};

class WordDictionary {
public:
    //Trie* t;
    //WordDictionary(){t = &Trie::getInstance();}
    // Adds a word into the data structure.
    void addWord(string word) {
        //Trie t = Trie::getInstance();
        Trie::getInstance().insert(word);
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        //Trie t = Trie::getInstance();
        return Trie::getInstance().search(word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


void test(){
    WordDictionary wd;
    
    wd.addWord("bad");//
    wd.addWord("dad");//
    wd.addWord("mad");//
    cout<<wd.search("pad")<<endl;// -> false
    cout<<wd.search("bad")<<endl;// -> true
    cout<<wd.search(".ad")<<endl;// -> true
    cout<<wd.search("b..")<<endl;// -> true
}
#endif /* _11_AddAndSearchWord_DataStructureDesign_h */
