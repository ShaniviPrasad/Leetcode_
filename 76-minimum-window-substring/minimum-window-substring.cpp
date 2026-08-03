class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int>mp;
      for(char ch:t) mp[ch]++;
      int j=0, i=0, start=0;
      string ans="";
      int mini=INT_MAX;
      int count=mp.size();
      while(j<s.size()){
        if(mp.find(s[j])!=mp.end()){
             mp[s[j]]--;
           if(mp[s[j]]==0) 
            count--;
        }
            while(count==0){
                if(j-i+1<mini){
                   mini=j-i+1;
                   start=i;
                   }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if( mp[s[i]]==1) count++;
                }
                i++;
        }
            j++;            
      } 
       if(mini==INT_MAX) return "";
      return s.substr(start, mini);
    }
};