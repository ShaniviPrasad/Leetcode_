class Solution {
public:
    bool isvalid(string& par){
        int count=0;
        for(char &ch:par){
            if(ch=='(') count++;
            else
            count--;
            if(count<0) return false;
        }
        return count==0;
    }
    void solve(string& par, vector<string>&ans, int n){
        if(par.length()==2*n){
            if(isvalid(par)){
                ans.push_back(par);
            }
            return;
        }
       par.push_back('(');
       solve(par,ans, n);
       par.pop_back();   
        par.push_back(')');
       solve(par,ans, n);
       par.pop_back();   
    }
    
    vector<string> generateParenthesis(int n) {
      vector<string>ans;
      string par="";
        solve(par,ans, n);
        return ans;
    }
};