class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=0;
        for(auto &s: strs){
            bool flag=0;
            for(auto ch:s){
                if(ch>='a' && ch<='z'){
                ans=max(ans, (int)s.size());
                flag=1; 
                break;
                }
            }
            if(flag==0)
            ans=max(ans, stoi(s));
        }
        
        return ans;
    }
};