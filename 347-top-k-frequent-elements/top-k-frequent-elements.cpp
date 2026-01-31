class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> maps;
        for(int x : nums) maps[x]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto &p : maps){
            bucket[p.second].push_back(p.first);
        }
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--){
            for(int x : bucket[i]){
                res.push_back(x);
                if(res.size() == k)
                break;
            }          
        }
        return res;
    }
};