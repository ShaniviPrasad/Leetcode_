class Solution {
public:
    int solve(int idx , int n, vector<int>&dp){
        if(idx>=n) return 1;
        if(dp[idx]!=0) return dp[idx];
         int case1=solve(idx+1 , n, dp);
        int case2= solve(idx+2, n, dp);
        return dp[idx]=case1+case2;
    }
    int climbStairs(int n) {
       vector<int>dp(n+1);
       return solve (1, n,dp);  
    }
};