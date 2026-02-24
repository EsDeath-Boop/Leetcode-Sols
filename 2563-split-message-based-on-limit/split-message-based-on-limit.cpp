class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int sa = 0;

        for (int k = 1; k <= n; ++k) {
            sa += to_string(k).size();
            int sb = to_string(k).size() * k;
            int sc = 3 * k;

            if (1LL * limit * k - (sa + sb + sc) >= n) {
                vector<string> ans;
                ans.reserve(k);

                int idx = 0;
                for (int i = 1; i <= k; ++i) {
                    string suffix = "<" + to_string(i) + "/" + to_string(k) + ">";
                    int take = limit - suffix.size();
                    ans.push_back(message.substr(idx, take) + suffix);
                    idx += take;
                }
                return ans;
            }
        }
        return {};
    }
};