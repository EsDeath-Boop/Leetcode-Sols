class Solution {
public:

    long long n;
    long long t[1000001][2];
    long long solve(vector<int>& nums, int idx, bool flag){
        if(idx >= n) return 0;
        if(t[idx][flag] != -1) return t[idx][flag];
        long long skip = solve(nums, idx+1, flag);
        long long val = nums[idx];
        if(flag != true){
            val = -val;
        }
        long long take = solve(nums, idx+1, !flag) + val;
        return t[idx][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, true);
    }
};