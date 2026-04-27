class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     int maxval=0;
     for(int x:nums) 
       maxval=max(x, maxval);
       vector<int>freq(maxval+1, 0);
     for(int x:nums){
        freq[x]+=x;
     }
       vector<int>dp(maxval+1, 0);
       dp[0]=0;
       dp[1]=freq[1];
       for(int i=2; i<=maxval; i++){
        int pick=dp[i-2]+freq[i];
        int skip=dp[i-1];
        dp[i]=max(pick, skip);
       }
       return dp[maxval];
    }
};
