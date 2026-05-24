class Solution {
public:
    int solve(vector<int>& jd, int n,int idx,int d,vector<vector<int>>&dp){
        if(d==1){
            int maxd=jd[idx];
            for(int i=idx; i<n; i++){
                maxd=max(maxd,jd[i]);
            }
            return maxd;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int maxd=jd[idx];
        int finalresult=INT_MAX;
        for(int i=idx; i<=n-d; i++){
            maxd=max(maxd, jd[i]);
            int result=maxd+solve(jd, n, i+1, d-1, dp);
            finalresult=min(finalresult, result);
        }
       return dp[idx][d]=finalresult;
    }
    int minDifficulty(vector<int>& jd, int d) {
          int n=jd.size();
          vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        if(n<d) return -1;
         return solve(jd , n, 0, d, dp);
        
    }
};