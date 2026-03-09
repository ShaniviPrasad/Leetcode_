class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto i= mp.begin(); i!=mp.end(); i++) {
            minheap.push({i->second, i->first});
            if(minheap.size()>k){
             minheap.pop();
            }
        }
        vector<int>ans;
        while(minheap.size()>0){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;
    }
};