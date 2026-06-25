class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int curSum = 0;
        long long valid = 0;
        long long res = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                valid += mp[curSum];
                curSum += 1;
            }else{
                curSum -= 1;
                valid -= mp[curSum];
            }

            mp[curSum] += 1;
            res += valid;
        }
        return res;
    }
};