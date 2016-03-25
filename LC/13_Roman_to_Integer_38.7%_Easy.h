/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    int CTI(char c){
        switch(c){
            case 'I': return 1;
            //break;
            case 'V': return 5;
            //break;
            case 'X': return 10;
            //break;
            case 'L': return 50;
           // break;
            case 'C': return 100;
            //break;
            case 'D': return 500;
            //break;
            case 'M': return 1000;
            //break;
            default: return 0;
           //break;
        }
    }
    int romanToInt(string s) {
        int result = CTI(s[0]);
        for(int i = 1; i <s.length(); i++){
            if(CTI(s[i])>CTI(s[i-1]))
            result +=(CTI(s[i])-2*CTI(s[i-1]));
            else
            result += CTI(s[i]);
        }
        return result;
    }
};