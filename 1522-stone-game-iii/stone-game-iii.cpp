class Solution {
public:
   int n;
    int calculatediff(int i,vector<int>& stoneValue,vector<int>&dp){
       if(i>=n) return 0;
       if(dp[i]!=-1) return dp[i];
       int result = INT_MIN;
        result=max(result,stoneValue[i]-calculatediff(i+1, stoneValue, dp));
       if(i+1<n) result=max(result,stoneValue[i]+stoneValue[i+1]-calculatediff(i+2, stoneValue, dp));
        if(i+2<n) result=max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-calculatediff(i+3, stoneValue, dp));
        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int>dp(n+1, -1);
        int diff=calculatediff(0, stoneValue, dp);
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else
        return "Tie";
    }
};