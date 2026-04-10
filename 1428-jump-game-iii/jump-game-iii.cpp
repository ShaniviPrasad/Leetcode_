class Solution {
public:
    bool solve(int i, vector<int>&arr, vector<bool>&vis){
        int n=arr.size();
        if(i<0 || i>=n) return false;
        if(vis[i]) return false;
        if(arr[i]==0) return true;
        vis[i]=true;
        return solve(i+arr[i], arr, vis) || solve(i-arr[i], arr, vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n);
        return solve(start, arr, vis);
    }
};