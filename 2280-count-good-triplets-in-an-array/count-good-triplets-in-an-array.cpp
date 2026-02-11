class Solution {
public:
    long long query(int st, int end, int i, int l, int r, vector<long long>& segT){
        if(l > end || r < st)
            return 0;

        if(l >= st && r <= end){
            return segT[i];
        }

        int mid = l + (r-l) / 2;

        long long left = query(st, end, 2*i+1, l, mid, segT);
        long long right = query(st, end, 2*i+2, mid+1, r, segT);

        return left + right;
    }
    void update(int i, int l, int r, int idx, vector<long long>& segT){
        if( l == r){
            segT[i] = 1;
            return;
        }
        int mid  = (l + r)  / 2;
        if(idx <= mid){
            update(2*i + 1, l, mid, idx, segT);
        }else{
            update(2*i+2, mid+1, r, idx, segT);
        }

        segT[i] = segT[2*i+1] + segT[2*i+2];
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int n = nums1.size();

        for(int i = 0; i< n; i++){
            mp[nums2[i]] = i;
        }

        vector<long long> segT(4*n);
        long long result = 0;

        // update(0, 0, n -1, mp[nums1[0]], segT);

        for(int i = 0; i <n; i++){
            int idx = mp[nums1[i]];

            long long leftCommonCnt = query(0, idx, 0, 0, n - 1, segT);
            long long leftUnCommonCnt = i - leftCommonCnt;
            long long elementsAfterIdxNums2 = n - 1 - idx;
            long long rightCommonCnt = elementsAfterIdxNums2 - leftUnCommonCnt;

            result += leftCommonCnt * rightCommonCnt;

            update(0, 0, n -1, idx, segT);

        }
        return result;
    }
};