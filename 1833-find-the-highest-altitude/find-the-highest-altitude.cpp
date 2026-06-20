class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>alt(n+1);
        alt[0]=0;
        for(int i=1; i<n+1; i++){
            alt[i]=alt[i-1]+gain[i-1];
        }
        int highest=INT_MIN;
        for(int i=0; i<n+1; i++){
            highest=max(highest, alt[i]);
        }
        return highest;
    }
};