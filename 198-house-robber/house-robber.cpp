class Solution {
public:
    // int t[101];

    // int solve(vector<int>& nums, int i, int n){
    //     if(i >= n) return 0;

    //     if(t[i] != -1){
    //         return t[i];
    //     }

    //     int skip = solve(nums, i+1, n);
    //     int select =nums[i] + solve(nums, i+2, n);

    //     return t[i] =  max(skip, select);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     memset(t, -1, sizeof(t));
    //     return solve(nums, 0, n);
    // }

    int rob(vector<int>& nums){
        int n = nums.size();

        vector<int> t(n+1, 0);

        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i <= n; i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(skip, steal);
        }
        return t[n];
    }
};