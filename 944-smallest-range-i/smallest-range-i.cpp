class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = INT_MIN, mini = INT_MAX;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        return max(0, maxi - mini - 2*k);
    }
};