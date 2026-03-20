class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            minH.push({it->second, it->first});
            if(minH.size() > k){
                minH.pop();
            }
        }
        while(minH.size()){
            res.push_back(minH.top().second);
            minH.pop();
        }
        return res;
    }
};