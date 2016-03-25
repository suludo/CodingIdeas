/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

//Think it as start at step 0
// so to step 1 take 1 step
class Solution {
public:

	    int climbStairs(int n) {
        int p = 1; //0 step
        int p1 = 0; //nothing before 0 step
        
        for(int i=1; i<=n; i++){
            int tmp = p;
            p = p+p1;
            p1 = tmp;
        }
        return p;
    } 
	
    int climbStairs1(int n) {
        int p = 1; //1 step
        int p1 = 1; //0 step
        
        for(int i=2; i<=n; i++){
            int tmp = p;
            p = p+p1;
            p1 = tmp;
        }
        return p;
    }
};