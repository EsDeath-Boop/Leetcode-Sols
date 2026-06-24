class Solution {
public:
    string solve(string &word){
        vector<int> arr(26, 0);

        for(char &c : word){
            arr[c - 'a']++;
        }

        string newWord = "";
        for(int i = 0; i < 26; i++){
            int freq = arr[i];

            if(freq > 0){
                newWord += string(freq, i + 'a');
            }
        }
        return newWord;
    }
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();

        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++){
            string temp = s[i];

            string newWord = solve(temp);

            mp[newWord].push_back(temp);
        }

        for(auto &it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};