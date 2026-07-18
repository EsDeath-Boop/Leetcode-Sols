class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxx = *max_element(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());

        return gcd(maxx, minn);
    }
};