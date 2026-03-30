class Solution {
public:
    int findPivot(MountainArray& mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        return low;   
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int ans1 = -1;
        int ans2 = -1;

        int pivot = findPivot(mountainArr);

        int low = 0, high = pivot;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) == target) {
                ans1 = mid;
                break;
            } 
            else if (mountainArr.get(mid) > target)
                high = mid - 1;      
            else
                low = mid + 1;
        }

        int low2 = pivot, high2 = n - 1;
        while (low2 <= high2) {
            int mid = low2 + (high2 - low2) / 2;

            if (mountainArr.get(mid) == target) {
                ans2 = mid;
                break;
            } 
            else if (mountainArr.get(mid) > target)
                low2 = mid + 1;      
            else
                high2 = mid - 1;
        }

        if (ans1 != -1) return ans1;
        return ans2;
    }
};