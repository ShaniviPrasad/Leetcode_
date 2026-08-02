class Solution {
public:
  int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
  }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            mini=min(mini, nums[i]);
            mx=max(mx, nums[i]);
        }
        return gcd(mini, mx);
    }
};