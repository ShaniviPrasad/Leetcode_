class Solution {
public:
    int calculateplayer1(int i, int j,vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        int take_i=nums[i]+min(calculateplayer1(i+2, j, nums),calculateplayer1(i+1, j-1, nums));
        int take_j=nums[j]+min(calculateplayer1(i+1, j-1, nums),calculateplayer1(i, j-2, nums));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int val:nums) total=total+val;
        int player_1=calculateplayer1(0, n-1, nums);
        int player_2=total-player_1;
        if(player_1>=player_2)return true;
        return false;
    }
};