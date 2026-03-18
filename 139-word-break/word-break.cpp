class Solution {
public:
    bool solve(int idx, string &s, int n, unordered_set<string> &str, vector<int>&dp) {
        if (idx == n) return true;
         if (dp[idx] != -1) return dp[idx];
        string temp = "";
        for (int j = idx; j < n; j++) {
            temp += s[j];
            if (str.find(temp) != str.end()) {
                if (solve(j + 1, s, n, str,dp))
                     return dp[idx] = 1;
            }
        }
       return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> str(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        int n = s.size();
        return solve(0, s, n, str,dp);
    }
};