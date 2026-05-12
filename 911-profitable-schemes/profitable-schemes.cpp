class Solution {
public:
   int N;
     int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int i, int p, int people, int &minProfit, vector<int>& group, vector<int>& profit ){
         
        if(people>N) return 0;
        if(i == group.size()){
           if(p >= minProfit) return dp[i][p][people]=1;
              else dp[i][p][people]= 0;
            }
            if(dp[i][p][people] != -1)
            return dp[i][p][people];

        long long not_take=solve(i+1, p, people, minProfit, group, profit)%MOD;
        long long take=solve(i+1, min(p+profit[i], minProfit) , people+group[i], minProfit, group, profit)%MOD;
        
        return dp[i][p][people]=(not_take%MOD +take%MOD)%MOD;
        
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
         N=n;
         int m=group.size();
        dp.resize(m+ 1,vector<vector<int>>( minProfit+ 1,vector<int>(n + 1, -1)));
       
        return solve(0, 0, 0, minProfit, group, profit);
        
    }
};