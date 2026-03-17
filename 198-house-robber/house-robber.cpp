class Solution {
public:
    int solve (int idx, vector<int>& nums,vector<int>&dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=solve(idx+1, nums, dp);
        int not_pick=nums[idx]+solve(idx+2, nums, dp);
        return dp[idx]=max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);

        return solve(0, nums, dp);
       
    }
};