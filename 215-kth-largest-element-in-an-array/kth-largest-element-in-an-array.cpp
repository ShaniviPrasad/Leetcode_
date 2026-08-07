class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int val:nums){
            minh.push(val);
            if(minh.size()>k) minh.pop();
        }
        return minh.top();
    }
};