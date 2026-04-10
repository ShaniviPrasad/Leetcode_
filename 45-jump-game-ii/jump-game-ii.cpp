class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i >= n-1) return 0;
        if(dp[i] != -1) return dp[i];
        int count = INT_MAX;
        for(int j = 1; j <= nums[i]; j++){
            if(i + j < n){
                int res = solve(i + j, nums, dp);
                if(res != INT_MAX){
                    count = min(count, res + 1);
                }
            }
        }
        return dp[i] = count;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};