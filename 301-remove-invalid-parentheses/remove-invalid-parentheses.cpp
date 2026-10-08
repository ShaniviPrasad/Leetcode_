class Solution {
public:
    unordered_set<string>st;
    int maxlen;
    void solve(string &s, int i, int count, string& curr){
        if(count<0) return ;
        int n=s.size();
        if(i==n){
            if(count==0){
               if(curr.size()>maxlen){
                 maxlen=curr.size();
                  st.clear();
            }
            if(curr.size()==maxlen) st.insert(curr);
            }
            return;
        }
            if(s[i]!='(' && s[i]!=')'){
                curr.push_back(s[i]);
                solve(s,i+1, count, curr);
                curr.pop_back();
                return;
            }
            curr.push_back(s[i]);
              solve(s, i + 1,count+(s[i] == '(' ? 1 : -1),curr);
            curr.pop_back();
            solve(s,i+1, count, curr);
    }
    vector<string> removeInvalidParentheses(string s) {
        st.clear();
        string curr="";
        maxlen=0;
        int count=0;
        solve(s, 0,0 , curr);
        return vector<string>(begin(st), end(st));
    }
};