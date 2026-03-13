class DSU{
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
    }
    int find_par(int x){
        if(parent[x]==x) return x;
        return parent[x]=find_par(parent[x]);
    }
    bool Union(int x,int y){  
        int px=find_par(x);
        int py=find_par(y);
        if(px==py) return false;
        if(rank[px]<rank[py])
            parent[px]=py;
        else if(rank[px]>rank[py])
            parent[py]=px;
        else{
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        sort(e.begin(), e.end());
        reverse(e.begin(), e.end());
        DSU alice(n);
        DSU bob(n);
        int remove=0;
        int aliceedge=0;
        int bobedge=0;
        int alice_edge=0 , bob_edge=0;
        for(int i=0; i<e.size(); i++){
            int type=e[i][0];
            int e1=e[i][1];
            int e2=e[i][2];
            if(type==3){
                if(alice.find_par(e1)==alice.find_par(e2) && 
                   bob.find_par(e1)==bob.find_par(e2)){
                    remove++;
                }
                else{
                    if(alice.find_par(e1)!=alice.find_par(e2)){
                        alice.Union(e1,e2);   
                        aliceedge++;
                    }
                    if(bob.find_par(e1)!=bob.find_par(e2)){
                        bob.Union(e1,e2);    
                        bobedge++;
                    }
                }
            }
            else if(type==2){
                if(bob.find_par(e1)==bob.find_par(e2)){
                    remove++;
                }
                else{
                    if(bob.find_par(e1)!=bob.find_par(e2)){
                        bob.Union(e1,e2);    
                        bobedge++;
                    }
                }
            }
            else if(type==1){
                if(alice.find_par(e1)==alice.find_par(e2)){
                    remove++;
                }
                else{
                    if(alice.find_par(e1)!=alice.find_par(e2)){
                        alice.Union(e1,e2);   
                        aliceedge++;
                    }
                }
            }
        }
        if(aliceedge!=n-1 || bobedge!=n-1)   
            return -1;
        return remove;
    }
};