/*
Implement pow(x, n).
*/

//pay attn:
//overflow, so don't include reverse signal
//minus sign handled by *x or /x
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        double d = myPow(x, n/2);
        if(n%2) return n<0 ? d*d/x : d*d*x;
        return d*d;
    }
};

/*
double myPow(double x, int n) { 
    if(n==0) return 1;
    double t = myPow(x,n/2);
    if(n%2) return n<0 ? 1/x*t*t : x*t*t;
    else return t*t;
}
*/