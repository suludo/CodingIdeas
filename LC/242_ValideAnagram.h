//
//  242_ValideAnagram.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _42_ValideAnagram_h
#define _42_ValideAnagram_h



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()-t.size()) return false;
        
        int mp[26]={0};
        
        for(int i=0; i<s.size(); i++)
            mp[s[i]-'a']++;
        for(int i=0; i<t.size(); i++)
            if(mp[t[i]-'a']==0) return false;
            else mp[t[i]-'a']--;
        
        return true;
    }
};


#endif /* _42_ValideAnagram_h */
