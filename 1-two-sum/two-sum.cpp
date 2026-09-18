class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int, int>mp;
     int rem=0;
      for(int i=0; i<nums.size(); i++){
        rem=target-nums[i];
        if(mp.find(rem)!=mp.end()) return {mp[rem], i};
        mp[nums[i]]=i;
     }
      return {};
    }
};