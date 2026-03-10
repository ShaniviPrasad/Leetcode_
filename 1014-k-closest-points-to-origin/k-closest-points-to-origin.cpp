class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxheap;
        vector<vector<int>>  ans;
        int n=points.size();
        for(int i=0; i<n; i++){
            maxheap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],  points[i][1]}});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
            while(maxheap.size()>0){
            pair<int,int> p=maxheap.top().second;
            maxheap.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;

    }
};