class Solution {
 /*  
    int climbToEnd(int n, vector<int> &dp) {
        if(n == 0)  return 1;
        if(n < 0)   return 0;

        if(dp[n] != -1) return dp[n];

        int ways1 = climbToEnd(n-1, dp);
        int ways2 = climbToEnd(n-2, dp);

        return dp[n] = (ways1 + ways2);
    }
*/
public:
    int climbStairs(int n) {
        
        /*
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];        
        */
        
	//Space Optimization.
        int prevJump1 = 1;
        int prevJump2 = 1;
        
        for(int i=2; i<=n; ++i) {
            int currJump = prevJump1 + prevJump2;
            prevJump1 = prevJump2;
            prevJump2 = currJump;
        }
        
        return prevJump2;
    }
};