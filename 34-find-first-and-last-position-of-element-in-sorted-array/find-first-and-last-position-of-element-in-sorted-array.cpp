class Solution {
public:
    int findleft_most(vector<int>nums, int target, int n){
       int lo=0;
       int hi=nums.size()-1;
       int left_most=-1;
       while(lo<=hi){
         int mid=lo+(hi-lo)/2;
         if(nums[mid]==target) {
            left_most=mid;
             hi=mid-1; 
       }
       else if(nums[mid]>target) hi=mid-1;
       else lo=mid+1;
    }
    return left_most;
    }
    int findright_most(vector<int>nums, int target, int n){
       int lo=0;
       int hi=nums.size()-1;
       int right_most=-1;
       while(lo<=hi){
         int mid=lo+(hi-lo)/2;
         if(nums[mid]==target) {
            right_most=mid;
             lo=mid+1; 
       }
       else if(nums[mid]>target) hi=mid-1;
       else lo=mid+1;
    }
    return right_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left_most=findleft_most(nums, target, n);
        int right_most=findright_most(nums, target,n);
         
         return {left_most, right_most};
    }
};