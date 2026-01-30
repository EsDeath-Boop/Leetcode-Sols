class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> res;
        int n = nums.size();
        
        for (int x : nums) m[x]++;
        
        for (auto &p : m) {
            if (p.second > n / 3)
                res.push_back(p.first);
        }
        return res;
    }
};
