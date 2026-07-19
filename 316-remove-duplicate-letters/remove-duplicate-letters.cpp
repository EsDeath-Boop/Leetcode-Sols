class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        string t;

        vector<bool> used(26, false);
        vector<int> lastIdx(26);

        for(int i = 0; i < n; i++){
            char c = s[i];
            lastIdx[c - 'a'] = i;
        }

        for(int i = 0; i < n; i++){
            char c = s[i];

            int idx = c - 'a';

            if(used[idx] == true)
                continue;
            
            while(t.size() > 0 && t.back() > c && lastIdx[t.back() - 'a'] > i){
                used[t.back() - 'a'] = false;
                t.pop_back();

            }
            used[c - 'a'] = true;
            t.push_back(c);
        }

        return t;
    }
};