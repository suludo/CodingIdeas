/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1) return s;
        vector<char> row;
        vector<vector<char>> ctn(nRows, row);
        
        for(int i=0; i<s.size(); i++){
            int index = i%(2*nRows-2);
            if(index<nRows){
                ctn[index].push_back(s[i]);
            }
            else{
                ctn[2*nRows-2-index].push_back(s[i]);
            }
        }
        string ret;
        for(int i=0; i<nRows; i++){
            for(int j=0; j<ctn[i].size(); j++)
                ret.push_back(ctn[i][j]);
        }
        return ret;
    }
};