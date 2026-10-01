class Solution {
public:
    int manhattan(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0]-points[p2][0]) +abs(points[p1][1]-points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        int n=points.size();
        vector<bool>inMST(n, false);
        int mincost=0;
        pq.push({0,0});
        while(!pq.empty()){
            int cost=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(!inMST[u]){
               inMST[u]=true;
               mincost+=cost;
               for(int i=0; i<n; i++){
                   if(!inMST[i]){
                    int edgewt=manhattan(points, u, i);
                    pq.push({edgewt,i});
                   }
               }
            }
        }
        return mincost;
    }
};