class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for (int i =0; i<n; i++) 
            total+=nums[i];
        int left_sum=0;
        for(int i=0 ; i<n; i++){
        int rightsum=total-left_sum-nums[i];
        if(left_sum == rightsum) 
        return i;
        left_sum += nums[i]; 
      }
        return -1;
    }
};