class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
       vector<int> ans(n,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                int d1 = abs(i-j);
                int d2 = abs(i-x) + 1 + abs(y-j);
                int d3 = abs(i-y) + 1 + abs(x-j);
                int dist = min(d1, min(d2,d3));
                ans[dist-1]++;
            }
        }
        return ans;
    }
};