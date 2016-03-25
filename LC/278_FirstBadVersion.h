#include <iostream>
#include <vector>
#include <cctype>
#include <ctime>
#include <cstdlib>

//#include <typeinfo>

using namespace std;
class api{
    //static int cnt;
public:
    static int cnt;
    vector<int> v;
    
    //return if is bad version => 1
    bool call(int i){
        api::cnt++;
        return i>=v.size() || v[i]==1;
    }

    api(int n){
        v.assign(n,1);
        srand(time(NULL));
        int k = rand()%n;

        v.assign(k, 0);
        //test when no bad version exists
        //v.assign(n,0);
    }
    static int getCount(){
        return cnt;}
    
};
//Given a vector of 000000111
//find where is the border between 0 and 1
// lower_bound(1)
int api::cnt = 0;
api a(n);

class Solution {
public:
    int badVersion(int n){

        int ret = -1;
        int l = 0, r = n-1;
        while(l<r){
            int m = l + (r-l)/2;
            
            if(a.isBad(m)){
                r = m;}
            else l = m+1;

        }

        return a.isBad(l) ? l:-1;
    }

};


int main()
{
    
   cout << endl << endl; 
   Solution s;
   cout<<s.badVersion(1000)<<endl;


   return 0;
}

