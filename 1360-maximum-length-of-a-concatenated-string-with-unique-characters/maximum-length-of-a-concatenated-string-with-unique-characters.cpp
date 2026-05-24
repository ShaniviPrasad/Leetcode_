class Solution {
public:
    bool isduplicate(string &s1, string &s2){
        int arr[26]={0};
        for(char &c:s1){
            if(arr[c-'a']>0) return true;
            else arr[c-'a']++;
        }
        for(char &c:s2){
            if(arr[c-'a']>0) return true;
        }
        return false;
    }
    int solve(vector<string>&arr, int i, string temp, int n){
       if(i>=n) return temp.size();
       int exclude=0;
       int include=0;
       if(isduplicate(arr[i], temp))
       exclude=solve(arr, i+1, temp, n);
       else{
        exclude=solve(arr, i+1, temp,n );
        include=solve(arr, i+1, temp+arr[i],n);
       }
       return max(exclude, include);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();
        int i=0;
        return solve(arr,i, temp, n);
    }
};