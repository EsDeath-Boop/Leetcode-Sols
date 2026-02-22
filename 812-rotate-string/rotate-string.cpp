class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            string newstr = "";

            if (i == n - 1) {
                newstr = string(1, s[i]) + s.substr(0, i);
            } else {
                newstr = string(1, s[i]) + s.substr(i + 1, n - i - 1) 
                         + s.substr(0, i);
            }

            if (goal == newstr)
                return true;
        }
        return false;
    }
};