class Solution {
public:
    int minAddToMakeValid(string s) {
        int addition=0;
        stack<char>st;
        for(char &ch:s){
            if(ch=='(') st.push(ch);
            else {
                if(st.empty()) addition++;
                else st.pop();
            }
        }
        return addition+st.size();
    }
};