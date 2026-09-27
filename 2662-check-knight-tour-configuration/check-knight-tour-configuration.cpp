class Solution {
public:
    bool solve(vector<vector<int>>& grid, int r, int c, int expval){
        int n = grid.size();
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval)
            return false;
        if(expval==n*n-1)
            return true;
        return solve(grid,r-2,c+1,expval+1) ||
               solve(grid,r-1,c+2,expval+1) ||
               solve(grid,r+1,c+2,expval+1) ||
               solve(grid,r+2,c+1,expval+1) ||
               solve(grid,r+2,c-1,expval+1) ||
               solve(grid,r+1,c-2,expval+1) ||
               solve(grid,r-1,c-2,expval+1) ||
               solve(grid,r-2,c-1,expval+1);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, 0);
    }
};