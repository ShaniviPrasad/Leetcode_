class Solution {
public:
    int longestValidParentheses(string s) {
       int open=0, close=0;
       int result=0;
       for(int i=0; i<s.size(); i++){
         if(s[i]=='(') open++;
         else
           close++;
         if(open==close) result=max(result, open+close);
         else if(close>open) open=close=0;
       } 
       open=close=0;
       for(int i=s.size()-1; i>=0; i--){
         if(s[i]==')') close++;
         else
           open++;
         if(open==close) result=max(result, open+close);
         else if(close<open) open=close=0;
       } 
       return result;
    }
};