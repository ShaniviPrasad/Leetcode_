class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixp(n);
        int p=nums[0];
        prefixp[0]=1;
        for(int i=1; i<n; i++){
            prefixp[i]=p;
            p*=nums[i];
        }
        p=nums[n-1]; 
        //suffixp[n-1]=1;
        for(int i=n-2; i>=0; i--){
            prefixp[i]*=p;
            p*=nums[i];
        }
        return prefixp;
    }
};