class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<int>& nums, int i, int prev){
        if(i >= n)
            return 0;

        if(prev!= -1 && t[i][prev] != -1)
            return t[i][prev];
        int take = 0;
        int skip = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + solve(nums, i+1, i);
        }
        skip = solve(nums, i+1, prev);

        if(prev != -1)
            t[i][prev] = max(take, skip);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        t.assign(n+1, vector<int>(n + 1, -1));
        return solve(nums, 0, -1);
    }
};