class Solution {
public:
    int solve(int i,vector<int>& nums, int prev , vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];
        int take=0;
        if(prev==-1 || nums[prev]<nums[i])
        take=1+solve(i+1, nums, i, dp);
        int skip=solve(i+1, nums, prev, dp);
        if(prev!=-1) dp[i][prev]=max(take, skip);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, nums, -1, dp);
    }
};