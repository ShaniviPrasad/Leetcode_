class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maax=0;
        for(int i=0; i<n; i++){
            if(i>maax) return false;
            maax=max(maax, i+nums[i]);
        }
        return true;
    }
};