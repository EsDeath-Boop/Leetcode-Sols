class Solution {
public:
    int t[101];

    int solve(vector<int>& nums, int i, int n){
        if( i > n) return 0;
        if(t[i] != -1){
            return t[i];
        }

        int skip = solve(nums, i +1, n);

        int steal = nums[i] + solve(nums, i +2, n);

        return t[i] =  max(skip, steal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        if( n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int i0thIndex = solve(nums, 0, n -2);
        memset(t, -1, sizeof(t));
        int i1stIndex = solve(nums, 1, n-1);
        return max(i0thIndex, i1stIndex);
        

    }
};