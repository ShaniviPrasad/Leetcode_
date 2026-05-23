class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost, vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n) return INT_MIN;
        int newcost=cost+(grid[i][j]>0);
        if(newcost>k) return INT_MIN;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];
        int right=solve(grid, k, i, j+1, newcost, dp );
        int down=solve(grid, k, i+1, j, newcost, dp );
        int best=max(right, down);
        if(best==INT_MIN) return dp[i][j][cost]=INT_MIN;
        return dp[i][j][cost]=grid[i][j]+best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size(); 
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        int result=solve(grid, k, 0, 0, 0, dp);
        return result==INT_MIN?-1:result;
    }
};