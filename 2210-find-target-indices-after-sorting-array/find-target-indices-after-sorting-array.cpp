class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n=nums.size();
        int low=0; 
        int high=n-1;
        while(low<=high){
           int mid=low+(high-low)/2;
           if(nums[mid]==target){
            int i=mid;
            int j=mid+1;
            while(i>=0 && nums[i]==target){
                ans.push_back(i);
                i--;
            }
            while(j<n && nums[j]==target){
                ans.push_back(j);
                j++;
            }
            break;
           }
           if(nums[mid]<target) low=mid+1;
           else high=mid-1;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
//if(mid+1==target)