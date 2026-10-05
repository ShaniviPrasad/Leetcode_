class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for (char ch : s) { if (!st.empty() && st.top() == ch) 
                st.pop();
            else 
               st.push(ch);
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
      return s;
    }
};