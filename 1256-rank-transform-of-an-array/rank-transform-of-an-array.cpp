class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>arrs=arr;
        sort(arrs.begin(), arrs.end());
        unordered_map<int,int>mp;
        int rank=1;
        for(int num:arrs){
            if(mp.find(num)==mp.end()) mp[num]=rank++;
        }
        vector<int>res(arr.size());
        for(int i=0; i<arr.size(); i++) res[i]=mp.at(arr[i]);
        return res;
    }
};