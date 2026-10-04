class Solution {
public:
    bool solve(int idx,int open , string& s, vector<vector<int>>&dp){
        if(idx==s.size()) return open==0;
        if(dp[idx][open]!=-1) return dp[idx][open];
        bool isvalid=false;
        if(s[idx]=='*'){
           isvalid = solve(idx+1, open+1, s, dp) ||
          solve(idx+1, open, s,dp);// empty
            if(open>0)  isvalid=isvalid ||solve(idx+1, open-1, s, dp); //close
        }
        else if(s[idx]=='(') isvalid=solve(idx+1, open+1, s, dp);
        else if(open>0)  isvalid=solve(idx+1, open-1, s, dp);
        return dp[idx][open]=isvalid;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
       return solve(0, 0 , s, dp);
    }
};