/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

//pay attn: use l<r, always has l==r after while loop if not returned yet.
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;
        int l=1, r = 1+x/2;
        while(l<r){
            int m = l+(r-l)/2;
            if(m==x/m) return m;
            if(m>x/m) r = m-1;
            else l = m+1;
        }
        return r>x/r ? r-1 : r;
    }
};