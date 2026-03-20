class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minH;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            minH.push({it->second, -it->first});
        }

        while (minH.size()) {
            int freq = minH.top().first;
            int num = -minH.top().second;

            while (freq--) {
                res.push_back(num);
            }

            minH.pop();
        }
        return res;
    }
};