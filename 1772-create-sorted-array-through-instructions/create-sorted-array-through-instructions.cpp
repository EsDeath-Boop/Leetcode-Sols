class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> bit;

    void update(int i) {
        while (i < bit.size()) {
            bit[i]++;
            i += i & -i;
        }
    }

    int query(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    int createSortedArray(vector<int>& instructions) {
        int maxVal = 100000;
        bit.assign(maxVal + 1, 0);

        long long cost = 0;
        int inserted = 0;

        for (int x : instructions) {
            int less = query(x - 1);
            int greater = inserted - query(x);
            cost = (cost + min(less, greater)) % MOD;

            update(x);
            inserted++;
        }
        return cost;
    }
};