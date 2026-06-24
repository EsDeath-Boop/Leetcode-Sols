class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++){
            string temp = s[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s[i]);
        }

        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};