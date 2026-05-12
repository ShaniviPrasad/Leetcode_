class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<long long>> dp;
    int solve(int song_count, int unique_song,int &n, int &goal, int &k ){
        if(song_count==goal){
            if(unique_song==n) return 1;
         return 0;
        }
        if (dp[song_count][unique_song] != -1)
            return dp[song_count][unique_song];
        long long result=0;
        if(unique_song<n)
        result+=(long long)(n-unique_song)*solve(song_count+1, unique_song+1, n, goal, k);
        if(unique_song>k)
        result+=(long long)(unique_song-k)*solve(song_count+1, unique_song, n, goal, k);
    
    return dp[song_count][unique_song]=result%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        dp.resize(goal + 1, vector<long long>(n + 1, -1));
        return solve(0, 0, n, goal, k);
    }
};