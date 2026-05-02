class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n = nums.size();
        // int i = 0;

        // while(i < n){
        //     if(nums[i+1] < nums[i]){
        //         i += nums[i];
        //     }else if(nums[i+1] > nums[i])
        //         i++;
        // }   

        // if(i == n-1)
        //     return true;
        // else
        //     return false;


        int n = nums.size();

        int maxReach = 0;

        for(int i = 0; i < n; i++){
            if(i > maxReach)
                return false;

            maxReach = max(maxReach, nums[i] + i);
        }
        return true;
    }
};