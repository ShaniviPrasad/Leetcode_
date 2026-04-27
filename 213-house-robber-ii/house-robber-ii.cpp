class Solution {
public:
    int solve(vector<int>& nums, int i, int end ){
        int n = end - i + 1;
    vector<int> dp(n, 0);
    dp[0] = nums[i];
    for (int j = 1; j < n; j++) {
        int pick = nums[i + j];
        if (j > 1) pick += dp[j - 2];
        int skip = dp[j - 1];
        dp[j] = max(pick, skip);
    }
    return dp[n - 1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int case1= solve(nums, 0, n-2);
        int case2= solve(nums, 1, n-1);
        return max(case1, case2);
        
    }
};