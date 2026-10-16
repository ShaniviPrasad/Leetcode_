class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()==0) return true;
        string ans="";
        for(char ch:s){
            if (ch >='A' && ch <='Z') {
                ch = tolower(ch);
                ans+=ch;
            }
            else if(!isalnum(ch)) continue;
            else ans+=ch;
        }
        int i=0;
        int j=ans.size()-1;
        while(i<=j){
            if(ans[i]==ans[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};