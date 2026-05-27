class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>low(26,-1);
        vector<int>up(26, -1);
        for(int i=0; i<word.size(); i++){
             char ch=word[i];
            if(islower(ch)) low[ch-'a']= i;
            else if(up[ch-'A']==-1) up[ch-'A']=i;
        }
        int count=0;
        for(int i=0; i<26; i++){
            if(low[i]!=-1 && up[i]!=-1 && low[i]<up[i]) count++;
        }
        return count;
    }
};