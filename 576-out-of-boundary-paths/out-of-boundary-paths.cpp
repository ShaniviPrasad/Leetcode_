class Solution {
public:
int find(int m,int n,int maxMove,int i,int j,vector<vector<vector<long long>>> &dp)
    {
        if(i <0 || j < 0 || i>=m || j>= n)
        {
            return 1;
        }
        if(maxMove == 0)
        {
            return 0;
        }
        if(dp[i][j][maxMove] != -1)
        {
            return dp[i][j][maxMove];
        }
        dp[i][j][maxMove]=((long long)find(m,n,maxMove-1,i-1,j,dp)+find(m,n,maxMove-1,i+1,j,dp)+find(m,n,maxMove-1,i,j-1,dp)+find(m,n,maxMove-1,i,j+1,dp))%(long long)(1e9+7);
        return dp[i][j][maxMove];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(maxMove+1,-1)));
        return find(m,n,maxMove,startRow,startColumn,dp);
    }
};