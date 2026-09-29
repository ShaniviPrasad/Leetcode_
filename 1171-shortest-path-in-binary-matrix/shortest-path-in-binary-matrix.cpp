class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
       priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0]=1;
        pq.push({1,{0,0}});
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==n-1) return d;
            for(int i=0; i<8; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0) {
                    if(dist[nr][nc]>d+1){
                        dist[nr][nc]=d+1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};