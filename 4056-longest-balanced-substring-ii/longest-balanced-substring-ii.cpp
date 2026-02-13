class Solution {
public:
    int helper(string &s, char char1, char char2) {
        int n = s.length();
        unordered_map<int, int> diff;
        int count1 = 0, count2 = 0, maxL = 0;
        diff[0] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] != char1 && s[i] != char2) {
                count1 = 0;
                count2 = 0;
                diff.clear();
                diff[0] = i;
                continue;
            }

            if (s[i] == char1) count1++;
            if (s[i] == char2) count2++;

            int d = count1 - count2;
            if (diff.count(d)) {
                maxL = max(maxL, i - diff[d]);
            } else {
                diff[d] = i;
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;

        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) count++;
            else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        unordered_map<string, int> diff;
        int ca = 0, cb = 0, cc = 0;
        diff["0#0"] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            if (s[i] == 'b') cb++;
            if (s[i] == 'c') cc++;

            string key = to_string(ca - cb) + "#" + to_string(ca - cc);
            if (diff.count(key)) {
                maxL = max(maxL, i - diff[key]);
            } else {
                diff[key] = i;
            }
        }

        return maxL;
    }
};