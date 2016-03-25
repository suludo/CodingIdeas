/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        if(a.size()>b.size()) return addBinary(b,a);
        string ret;
        int i=0;
        int aux = 0;
        int la = a.size();
        int lb = b.size();
        while(i<lb){
            int sum = b[lb-1-i]-'0';
            if(i<la)
                sum += a[la-1-i]-'0';
            sum += aux;
            aux = sum/2;
            sum = sum%2;
            ret += to_string(sum);
            i++;
        }
        if(aux)
            ret += "1";
        reverse(ret.begin(), ret.end());
        return ret;
    }
};