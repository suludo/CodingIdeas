/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int i=0;
        int start = 0;
        int end = 0;
        while(i<words.size()){
            int sum = words[i].size();
            start = i;
            while(i<words.size()-1){
                if((sum+words[i+1].size()+1)>L) break;
                sum += (words[i+1].size()+1);
                i++;
            }
            end = i;
            sum = 0;
            for(int j=start; j<=end; j++)
                sum += words[j].size();
            int nSpace = L-sum;
            int nGap = end-start;
            string line;
			//one word at current line
            if(nGap==0){
                line += words[start];
                line.append(L-line.size(), ' ');
                ret.push_back(line);
                i++;
                continue;
            }
            int avrSpace = nSpace/nGap;
            
            if(end == (words.size()-1)){
                for(int j=start; j<=end; j++){
                    line += words[j];
                    if(j<end) line += ' ';
                    else line.append(L-line.size(), ' ');
                }
            }//last line
            else if(nSpace%nGap == 0){
                for(int j=start; j<=end; j++){
                    line += words[j];
                    if(j<end) line.append(avrSpace, ' ');
                }
            }
            else{
                nSpace = nSpace%nGap;
                for(int j=start; j<=end; j++){
                    line += words[j];
                    if(j==end) break;
                    if(nSpace){
                        line.append(avrSpace+1, ' ');
                        nSpace--;
                    }
                    else line.append(avrSpace, ' ');
                }
            }
            ret.push_back(line);
            i++;
        }
        return ret;
    }
};