class Solution {
    vector<int> original;
    vector<int> curr;

public:
    Solution(vector<int>& nums) {
        original = nums;
        curr = nums;
        srand(time(NULL));
    }

    vector<int> reset() {
        curr = original;
        return curr;
    }

    vector<int> shuffle() {
        int n = curr.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(curr[i], curr[j]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */