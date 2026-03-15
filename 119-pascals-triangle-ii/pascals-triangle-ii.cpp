class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;
        for(int i=0; i<=rowIndex; i++){
            vector<int>a(i+1);
            ans.push_back(a);
            for(int j=0; j<=i; j++){
                if(j==0 || i==j) ans[i][j]=1;
                else 
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans[rowIndex];
    }
};