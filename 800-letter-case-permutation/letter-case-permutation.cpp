class Solution {
public:
    void solve(string s, string& ans, vector<string>& all){
        if(s.size()==0){
            all.push_back(ans);
            return;
        }
        string ans1=ans;
        string ans2=ans;
        if(isalpha(s[0])){
            ans1.push_back(tolower(s[0]));
            ans2.push_back(toupper(s[0]));
             s.erase(s.begin());
            solve(s, ans1, all);
            solve(s, ans2, all);
        }
        else{
            ans.push_back(s[0]);
             s.erase(s.begin());
            solve(s, ans, all);
        }
       
    }
    vector<string> letterCasePermutation(string s) {
        string ans="";
        vector<string>all;
        solve(s, ans, all);
        return all;
    }
};