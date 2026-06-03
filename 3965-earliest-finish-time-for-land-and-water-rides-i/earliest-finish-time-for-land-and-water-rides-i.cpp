class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
       int n=landStartTime.size();
        int m=waterStartTime.size();
        int res=INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int landtime=landStartTime[i]+landDuration[i];
                int landwater=max(landtime,waterStartTime[j])+waterDuration[j];
                res=min(res, landwater);
               int watertime=waterStartTime[j]+waterDuration[j];
               int waterland=max(watertime,landStartTime[i])+landDuration[i];
                res=min(res, waterland);
            }
        }
        return res;
    }
};