class Solution {
public:
 void dfs(int node, vector<vector<int>>&adj, vector<int>&vis , int &v, int &e ){
    vis[node]=1;
    v++;
    e+=adj[node].size();
    for(auto it: adj[node]){
        if(!vis[it]){
          dfs(it, adj,vis, v, e);
        }
    }
 }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int result=0;
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int v=0;
                int e=0;
                dfs(i, adj,vis, v, e);
               if((v*(v-1))==e){
                result++;
              }
            }
        }
        return result;
    }
};