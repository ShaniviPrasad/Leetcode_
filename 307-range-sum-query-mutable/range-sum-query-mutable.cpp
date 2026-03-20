class NumArray {
public:
vector<int>st;
int n;
 void built(vector<int>& nums,int i, int lo, int hi){
    if(lo==hi){
        st[i]=nums[lo];
        return;
    }
    int mid= lo+(hi-lo)/2;
    built(nums, 2*i+1, lo, mid);
    built(nums, 2*i+2, mid+1, hi);
    st[i]=st[2*i+1]+st[2*i+2];
 }
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n);
        built(nums,0, 0, n-1);
    }
    void updateval(int i, int lo, int hi, int& index, int& val){
            if(lo==hi) {
            st[i]=val;
            return;
            }
            int mid=(lo+hi)/2;
            if(index<=mid) updateval(2*i+1, lo, mid, index, val);
            else
             updateval(2*i+2, mid+1, hi, index, val);
             st[i]=st[2*i+1]+st[2*i+2];

    }
    void update(int index, int val) {
        updateval(0, 0, n-1, index, val);
    }
    int sum(int i, int lo, int hi, int l, int r){
        if(l>hi || r<lo) return 0;
        if(lo>=l && hi<=r) return st[i];
        int mid= (lo+hi)/2;
        return sum(2*i+1, lo, mid, l, r)+sum(2*i+2, mid+1, hi, l, r);
    }
    
    int sumRange(int l, int r) {
        return sum(0, 0, n-1, l, r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */