/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int aux = 1;
        vector<int> ret;
        if(digits.empty()) return ret;
        for(int i=digits.size()-1; i>=0; i--){
            int val = (digits[i]+aux)%10;
            aux = (digits[i]+aux)/10;
            digits[i] = val;
        }
        if(aux==1)
            ret.push_back(aux);
        ret.insert(ret.end(), digits.begin(), digits.end());
        return ret;
    }
};