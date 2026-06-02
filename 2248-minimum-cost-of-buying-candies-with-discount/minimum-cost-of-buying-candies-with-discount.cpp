class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size()-1;
        int ans=0, k=0;
        sort(cost.begin(), cost.end());
        while(n>=0){
            if(k==2){ 
                k=0;
                n--;
                continue;
            }
            else{
                ans+=cost[n];
                k++;
                n--;
            }
        }
        return ans;
    }
};