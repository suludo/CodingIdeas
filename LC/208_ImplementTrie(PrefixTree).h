//
//  208_ImplementTrie(PrefixTree).h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _08_ImplementTrie_PrefixTree__h
#define _08_ImplementTrie_PrefixTree__h

class TrieNode {
public:
    unordered_map<unsigned char, TrieNode*> mp;
    bool leaf;
    // Initialize your data structure here.
    TrieNode(bool l = false) {
        leaf = l;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;
        for(int i=0; i<s.size(); i++){
            if(cur->mp.find(s[i])==cur->mp.end()){
                TrieNode* newNode = new TrieNode();
                cur->mp[s[i]] = newNode;
                cur = newNode;
            }
            else{
                cur = cur->mp[s[i]];
            }
        }
        cur->leaf = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* cur = root;
        for(int i=0; i<key.size(); i++){
            if(cur->mp.find(key[i])==cur->mp.end())
                return false;
            cur = cur->mp[key[i]];
        }
        return cur->leaf;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0; i<prefix.size(); i++){
            if(cur->mp.find(prefix[i])==cur->mp.end())
                return false;
            cur = cur->mp[prefix[i]];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


#endif /* _08_ImplementTrie_PrefixTree__h */
