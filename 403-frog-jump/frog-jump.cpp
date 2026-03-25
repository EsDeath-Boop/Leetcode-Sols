class Solution {
public:
    unordered_map<int,int> pos;
    int dp[2001][2001];

    bool solve(vector<int>& stones, int i, int k) {
        if (i == stones.size() - 1) return true;
        if (dp[i][k] != -1) return dp[i][k];

        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump > 0) {
                int next = stones[i] + jump;
                if (pos.count(next)) {
                    if (solve(stones, pos[next], jump))
                        return dp[i][k] = 1;
                }
            }
        }
        return dp[i][k] = 0;
    }

    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < stones.size(); i++)
            pos[stones[i]] = i;
        return solve(stones, 0, 0);
    }
};