class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int candy=0;
        sort(cost.begin(), cost.end());
        for(int i:cost) candy+=i;
        for(int j=n-3; j>=0; j-=3) candy-=cost[j];
        return candy;
    }
};