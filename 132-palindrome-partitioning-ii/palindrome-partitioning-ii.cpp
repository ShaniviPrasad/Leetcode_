class Solution {
public:
    bool ispalin(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, vector<int>&dp){
        if(i==s.length()) return 0;
        if(dp[i]!=-1) return dp[i];
         int cuts=INT_MAX;
        for(int k=i; k<s.length() ; k++){
           if(ispalin(s, i,k)) {
            int temp=1+solve(s, k+1,dp);
            cuts=min(cuts, temp);
        }  
    }
     return dp[i]=cuts;
    }
    int minCut(string s) {
        
        int n=s.length();
        vector<int>dp(n,-1);
        int ans=solve(s, 0,dp);
        return ans-1;
    }
};