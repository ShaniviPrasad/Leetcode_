class Solution {
public:
    vector<int>ans;
     void arr(int n) {
        ans.clear();
        while(n>0){
            ans.push_back(n%10);
            n/=10;
        }
    }
    int maxProduct(int n) {
        arr(n);
          int curr_max=ans[0];
          int result=0;
          for(int i=1; i<ans.size(); i++){
            result=max(result, curr_max*ans[i]);
            curr_max=max(curr_max, ans[i]);
          }
         return result;
    }
};