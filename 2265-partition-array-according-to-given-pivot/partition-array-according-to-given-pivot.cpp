class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      int n=nums.size();
      vector<int>ans(n);
      int idx=0;
      for(int num:nums){
        if(num<pivot) ans[idx++]=num;
      }
      for(int num:nums){
        if(num==pivot) ans[idx++]=num;
      }
      for(int num:nums){
        if(num>pivot) ans[idx++]=num;
      }
     return ans;
    }
};