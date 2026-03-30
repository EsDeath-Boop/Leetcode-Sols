class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int ans = -1;

        if(n == 1)
            return 0;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid > 0 && mid < n-1){
                if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                    ans = mid;
                    break;
                }else if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }else if(mid == 0){
                if(nums[0] > nums[1]){
                    ans = 0;
                    break;
                }
                else{
                    ans = 1;
                    break;
                }
            }else if(mid == n - 1){
                if(nums[n-1] > nums[n-2]){
                    ans = n - 1;
                    break;
                }
                else{
                    ans = n-2;
                    break;
                }
            }
        }
        return ans;
    }
};