#include <iostream>
#include <vector>
#include <cctype>
//#include <typeinfo>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        if(num<0) return ret;
        
        ret.push_back(0);
        int ub = 1, i=1, j=0;
        while(i<=num){
            ret.push_back(ret[j++]+1);
            if(j==ub){ 
                ub *= 2;
                j = 0;
            }
            i++;
        }
        return ret;
    }
};

void test()
{
   cout << "Hello World" << endl; 
   Solution s;
   vector<int> ret = s.countBits(34);
   for(int i=0; i<ret.size(); i++)
    cout<<ret[i]<<"  |   ";
   cout << endl;
}

