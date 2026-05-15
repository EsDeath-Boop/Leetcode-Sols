class Solution {
public:
    int findMin(vector<int>& nums) {
        int minE = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minE)
                minE = nums[i];
        }
        return minE;
    }
};