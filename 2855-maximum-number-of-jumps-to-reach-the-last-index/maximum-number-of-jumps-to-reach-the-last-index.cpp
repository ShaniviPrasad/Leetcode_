class Solution {
public:
    int solve(int i,vector<int>& nums, int target ,int n, vector<int>&dp) {
        if(i==n-1) return dp[i]= 0;
        int result=INT_MIN;
        if(dp[i]!=INT_MIN) return dp[i];
        for(int j=i+1; j<n; j++) {
          if(abs(nums[i]-nums[j]) <= target) {
            int temp=1+solve(j, nums, target, n ,dp);
            result=max(result,temp);
          }
        }
    return dp[i]=result;                
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        int result= solve(0, nums, target, n, dp);
        return result < 0 ?-1 : result;
    }
};