class Solution {
public:
    int findLeft(vector<int>& nums, int target, int n){
        int low = 0;
        int high = n - 1;

        int leftMost = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                leftMost = mid;
                high = mid -1;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return leftMost;
    }

    int findRight(vector<int>& nums, int target, int n){
        int low = 0;
        int high = n -1;

        int rightMost = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                rightMost = mid;
                low = mid + 1;
            }else if(nums[mid] > target)    
                high = mid - 1;
            else
                low = mid+1;

        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int leftMost = findLeft(nums, target, n);
        int rightMost = findRight(nums, target, n);

        return {leftMost, rightMost};
    }
};