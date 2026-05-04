class Solution {
public:
    bool solve(int n, int sum, vector<int>& nums, vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(n == 0) return false;
        if(dp[n][sum] != -1) return dp[n][sum];
        bool skip = solve(n-1, sum, nums, dp);
        bool take = false;
        if(nums[n-1] <= sum)
        take = solve(n-1, sum - nums[n-1], nums, dp);
        return dp[n][sum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(n, sum/2, nums, dp);
    }
};