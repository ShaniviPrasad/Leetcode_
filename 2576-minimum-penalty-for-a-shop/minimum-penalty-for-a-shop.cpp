class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>pref(n+1);
        vector<int>suf(n+1);
        pref[0]=0;
        for(int i=0; i<n; i++){
             pref[i+1]=pref[i]+((customers[i]=='N')?1:0);
        }
        suf[n]=0;
        for(int i=n-1; i>=0; i--){
             suf[i]=suf[i+1]+((customers[i]=='Y')? 1:0);
        }
        int minpen=INT_MAX;
        for(int i=0; i<=n; i++){
            pref[i]+=suf[i];
            int pen=pref[i];
            minpen=min(minpen, pen);
        }
        for(int i=0; i<n; i++){
            int pen=pref[i];
            if(pen==minpen) return i;
        }
        return n;
    }
};