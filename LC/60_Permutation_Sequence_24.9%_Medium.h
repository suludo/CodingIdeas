/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        if(n<1 || k<1) return ret;
        vector<long> facNums(n,1);
        vector<int> num(n,0);
        
        for(int i=0; i<n; i++){
            if(i==0)
                facNums[i] = 1;
            else
                facNums[i] = i*facNums[i-1];
            num[i] = i+1;
        }
        
        for(int i=n-1; i>=0; i--){
            int v = (k-1) / facNums[i];
            char c = '0'+num[v];
            ret+=c;
            num.erase(num.begin()+v);
            k -= v*facNums[i];
        }
        
    
        return ret;
    }
};