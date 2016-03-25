/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
// REVIEW: https://leetcode.com/discuss/11469/one-easy-solution-with-c


//Idea is use a vector to store all the digits of the product
//The key part is to use a vector to store all digits REVERSELY. after the calculation, find the rightmost NON-Zero digits and convert it to a string.

class Solution {
public:
    string multiply(string num1, string num2) {

        unsigned int l1=num1.size(),l2=num2.size();
        if (l1==0||l2==0) return "0";

        vector<int> v(l1+l2,0);

        for (unsigned int i=0;i<l1;i++){
            int carry=0;
            int n1=(int)(num1[l1-i-1]-'0');//Calculate from rightmost to left
            for (unsigned int j=0;j<l2;j++){
                int n2=(num2[l2-j-1]-'0');//Calculate from rightmost to left

                int sum=n1*n2+v[i+j]+carry;
                carry=sum/10;
                v[i+j]=sum%10;
            }
            if (carry>0)
                v[i+l2]+=carry;

        }
        int start=l1+l2-1;
        while(v[start]==0) start--;
        if (start==-1) return "0";

        string s="";
        for (int i=start;i>=0;i--)
            s+=(char)(v[i]+'0');
        return s;
    }
};


class Solution {
public:

    string add(string s1, string s2){
        if(s1.empty()) return s2;
        if(s2.empty()) return s1;
        if(s1.size()>s2.size()) return add(s2, s1);
        //cout<<s1.c_str()<<endl;
        //cout<<s2.c_str()<<endl;
        int l1 = s1.size();
        int l2 = s2.size();
        
        s1.insert(s1.begin(),l2-l1, '0');

        int len = l2;
        int aux = 0;
        for(int i=len-1; i>=0; i--){
            int i1 = s1[i]-'0';
            int i2 = s2[i]-'0';
            int val = (i1+i2+aux)%10;
            aux = (i1+i2+aux)/10;
            s1[i] = '0'+val;
        }
        if(aux>0)
            s1 = '1' + s1;
        //    s1.insert(s1.begin(), 1, '1');
        return s1;
    }
    
    string mult(string s, int m){ //m range 0-9
    
        if(s.empty()) return s;
        if(m==0) return "0";
        int aux = 0;
        for(int i=s.size()-1; i>=0; i--){
            int d = s[i]-'0';
            int val = (d*m+aux)%10;
            aux = (d*m+aux)/10;
            s[i] = '0'+val;
        }
        if(aux>0)
            s = (char)('0'+aux)+s;
       //    s.insert(s.begin(), 1, '0'+aux);
       
        return s;
    }
    
    string multiply(string num1, string num2) {
        string ret;
        if(num1.empty() || num2.empty()) return ret;
        ret = "0";
        if(num1=="0" || num2=="0") return ret;
        for(int i=0; i<num2.size(); i++){
            int m = num2[num2.size()-i-1]-'0';
            string res = mult(num1, m);
            res.insert(res.end(), i, '0');
            ret = add(ret, res);
        }
        return ret;
    }
};