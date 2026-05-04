class Solution {
public:
int solve(int n, int sum, vector<int>& nums, vector<vector<int>>&dp){
         if(n == 0){
            if(sum == 0) return 1;
            return 0;
        }   
        if(dp[n][sum] != -1) return dp[n][sum];
        int skip = solve(n-1, sum, nums, dp);
        int take = 0;
        if(nums[n-1] <= sum)
            take = solve(n-1, sum - nums[n-1], nums, dp);
        return dp[n][sum] = take + skip;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
        int arrsum=0;
        for(int x : nums) arrsum += x;
        if(abs(target) > arrsum) return 0;
        if((arrsum+target)%2!=0) return 0;
        int sum=(target+arrsum)/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(n, sum, nums, dp); 
    }
};