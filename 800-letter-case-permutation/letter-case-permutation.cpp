class Solution {
public:
    void solve(string s, string ans, vector<string>& all){
        if(s.size()==0){
            all.push_back(ans);
            return;
        }
       char ch = s[0];
       s.erase(s.begin());
        if(isalpha(ch)){
            solve(s, ans+(char)tolower(ch),all);
            solve(s, ans+(char)toupper(ch),all);
        }
        else{
            solve(s, ans+ch, all);
        }
       
    }
    vector<string> letterCasePermutation(string s) {
        string ans="";
        vector<string>all;
        solve(s, ans, all);
        return all;
    }
};