class NumArray {

    vector<int> seg;
    int n;
public:
    int query(int left, int right, int i, int l, int r){
        int mid = (l + r) / 2;
        if(l > right || r < left){
            return 0;
        }

        if(l >= left && r <= right){
            return seg[i];
        }
        return query(left, right, 2* i+1, l, mid) + query(left, right, 2*i+2, mid+1, r);
    }
    void updateTree(int index, int val, int i, int l, int r){
        if( l == r){
            seg[i] = val;
            return;
        }

        int mid = ( l + r) / 2;
        if(index <= mid){
            updateTree(index, val, 2 * i + 1, l, mid);
        }else{
            updateTree(index, val, 2*i+2, mid+1, r);
        }

        seg[i] = seg[2* i+1] + seg[2*i+2];
    }
    void build(int i, int l, int r, vector<int>& nums){
        if(l == r){
            seg[i] = nums[l];
            return;
        }
        int mid = (l+r) / 2;
        build(2*i + 1, l, mid, nums);
        build(2*i + 2, mid+1, r, nums);

        seg[i] = seg[2* i+1] + seg[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        return updateTree(index, val, 0, 0, n -1);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */