class Solution {
public:
    string decodeString(string s) {
        stack<string>stackstr;
        stack<int>stackno;
        string currstring="";
        int currno=0;
        for(char c:s){
            if(isdigit(c)) currno= currno* 10 + (c - '0');
            else if(c=='['){
            stackstr.push(currstring);
            stackno.push(currno);
            currstring="";
            currno=0;
            }
             else if(c==']'){
             int prevno=stackno.top();
             stackno.pop();
             string prevstring=stackstr.top();
             stackstr.pop();
             string temp = "";
             for (int i = 0; i < prevno; i++) {
                 temp += currstring;
                }   
             currstring = prevstring + temp;
            }
             else
             currstring+=c;
        }
        return currstring;
    }
};