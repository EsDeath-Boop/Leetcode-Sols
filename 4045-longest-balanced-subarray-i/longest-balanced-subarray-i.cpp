class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        for(int i = 0; i < n; i ++){
            set<int> even;
            set<int> odd;
            for(int j = i; j >= 0; j --){
                if(nums[j] % 2) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size() == even.size()){
                    ans = max(ans, i - j + 1);
                }
            }
        }
        return ans;
    }
};