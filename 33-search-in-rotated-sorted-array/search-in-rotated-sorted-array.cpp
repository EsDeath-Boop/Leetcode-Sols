class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int findPivot(vector<int>& nums){
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low; // pivot index
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        // search in left half
        int res = binarySearch(nums, target, 0, pivot - 1);
        if(res != -1) return res;

        // search in right half
        return binarySearch(nums, target, pivot, n - 1);
    }
};