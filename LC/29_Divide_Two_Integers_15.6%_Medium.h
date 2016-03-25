/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return -INT_MAX;
        if(dividend==0) return 0;
        if(divisor==1) return dividend;
        
        //long long dd = abs((double)dividend);
        //long long dr = abs((double)divisor);
        
        long long dd = ((double)dividend);
        long long dr = ((double)divisor);
        
        dd = dd<0 ? -dd:dd;
        dr = dr<0 ? -dr:dr;
    
        if(dd<dr) return 0;
        
        int res = 0;
        while(dd>=dr){
            int k=0;
            while((dr<<k)<=dd)
                k++;
            res += 1<<(k-1);
            dd -= dr<<(k-1);
        }
        if((dividend>0 && divisor<0)||(dividend<0&&divisor>0))
            return -res;
        return res;
    }
};