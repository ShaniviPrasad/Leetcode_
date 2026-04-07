class Solution {
public:
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>>& dp) {
        if(i == w1.size()) return w2.size() - j;
        if(j == w2.size()) return w1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i] == w2[j]) 
            return dp[i][j] = solve(w1, w2, i+1, j+1, dp);
        int insert = 1 + solve(w1, w2, i, j+1, dp);
        int delet  = 1 + solve(w1, w2, i+1, j, dp);
        int replace= 1 + solve(w1, w2, i+1, j+1, dp);

        return dp[i][j] = min(insert, min(delet, replace));
    }
    int minDistance(string w1, string w2) {
        int m = w1.size(), n = w2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(w1, w2, 0, 0, dp);
    }
};