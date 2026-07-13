class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixp(n);
        vector<int>suffixp(n);
        vector<int>ans(n);
        int p=nums[0];
        prefixp[0]=1;
        for(int i=1; i<n; i++){
            prefixp[i]=p;
            p*=nums[i];
        }
        p=nums[n-1]; 
        suffixp[n-1]=1;
        for(int i=n-2; i>=0; i--){
            suffixp[i]=p;
            p*=nums[i];
        }
        for(int i=0; i<n; i++){
           ans[i]=prefixp[i]*suffixp[i];
        }
        return ans;
    }
};