#include <vector>
using namespace std;
class Solution {
public:
    int solve(int num, vector<int>& dp) {
        if (num == 0) return 0;
        if (dp[num] != -1) return dp[num];
        int rem = solve(num / 10, dp);
        int d = num % 10;
        int check_d;
        if (d == 0 || d == 1 || d == 8) 
            check_d = 0;
        else if (d == 2 || d == 5 || d == 6 || d == 9) 
            check_d = 1;
        else 
            return dp[num] = 2;
        if (rem == 2 || check_d == 2) return dp[num] = 2;
        if (rem == 1 || check_d == 1)
            return dp[num] = 1;

        return dp[num] = 0;
    }
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, -1);
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (solve(i, dp) == 1) {
                count++;
            }
        }
        return count;
    }
};