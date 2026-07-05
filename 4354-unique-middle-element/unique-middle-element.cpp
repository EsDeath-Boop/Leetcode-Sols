class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == nums[n/ 2])
                count++;
        }

        if(count == 1)
            return true;

        return false;
    }
};