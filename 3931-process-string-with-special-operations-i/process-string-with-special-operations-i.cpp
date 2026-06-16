class Solution {
public:
    string processStr(string s) {
        vector<char> a;

        for (char c : s) {
            if (c == '#') {
                a.insert(a.end(), a.begin(), a.end());
            }
            else if (c == '*') {
                if (!a.empty()) {
                    a.pop_back();
                }
            }
            else if (c == '%') {
                reverse(a.begin(), a.end());
            }
            else {
                a.push_back(c);
            }
        }

        return string(a.begin(), a.end());
    }
};