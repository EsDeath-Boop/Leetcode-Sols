class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        map<int ,int> mp;

        for(auto &x : nums){
            mp[x]++;
        }

        int MAX = *max_element(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 1; ; i++){
            if(mp.find(i) == mp.end())
                return i;
        }
        return MAX+1;
        
    }
};