class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = INT_MIN;
        int maxi = INT_MIN;

        for(int j = k; j < n; j++) {
            maxi = max(maxi, nums[j - k]);
            ans = max(ans, maxi + nums[j]);
        }

        return ans;
    }
};