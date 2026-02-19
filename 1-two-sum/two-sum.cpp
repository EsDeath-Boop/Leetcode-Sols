class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        for(i = 0; i < nums.size(); i++){
            for(j = n - 1; j > i; j--){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }

        }
        return {};
        
    }
};