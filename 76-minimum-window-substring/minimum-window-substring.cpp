class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(t.length() > n)
            return "";

        unordered_map<char, int> mp;

        for(char &ch : t){
            mp[ch]++;
        }

        int i = 0, j = 0;
        int startI = 0;
        int windowSize = INT_MAX;
        int count = t.length();

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0)
                count--;
            mp[ch]--;

            while(count == 0){
                int currWin = j - i + 1;
                if(currWin < windowSize){
                    windowSize = currWin;
                    startI = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    count++;
                }
                i++;
            }
            j++;
        }
        return windowSize == INT_MAX ? "" : s.substr(startI, windowSize);
    }
};