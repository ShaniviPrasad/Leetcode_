class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto e:flights){
            int u=e[0];
            int v=e[1];
            int cost=e[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int, pair<int, int>>>q; // {node, {cost, stop}}
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({src, {0, -1}});
        while(!q.empty()){
            int u=q.front().first;
            int cost=q.front().second.first;
            int stop=q.front().second.second;
            q.pop();
            //if(stop>k) continue;
            for(auto e:adj[u]){
                int v=e.first;
                int price=e.second;
                if(dist[v]>cost+price && stop+1<=k){
                    dist[v]=cost+price;
                    q.push({v,{dist[v],stop+1}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};