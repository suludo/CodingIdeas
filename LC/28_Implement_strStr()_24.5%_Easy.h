/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int nh = haystack.size();
        int nn = needle.size();
        
        int in = 0;
        int ih = 0;

        while(ih<=nh-nn){
            in = 0;
            int j = ih;
            while(j<nh && haystack[j]==needle[in]){
                j++; in++;
            }
            if(in==nn) return ih; 
            ih++;
        }
        return -1;
    }
};