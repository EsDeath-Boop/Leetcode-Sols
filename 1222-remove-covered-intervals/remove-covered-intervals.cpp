class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int end = 0;
        int count = 0;

        for (auto& nums : v) {
            if (nums[1] > end) {
                count++;
                end = nums[1];
            }
        }
        return count;
    }
};