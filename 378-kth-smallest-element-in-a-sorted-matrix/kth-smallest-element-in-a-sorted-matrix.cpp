class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int>maxh;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                maxh.push(matrix[i][j]);
                if(maxh.size()>k) maxh.pop();
            }
        }
        return maxh.top();
    }
};