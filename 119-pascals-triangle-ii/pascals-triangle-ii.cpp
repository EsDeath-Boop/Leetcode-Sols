class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> t(rowIndex + 1, 0);
        t[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                t[j] = t[j] + t[j - 1];
            }
        }

        return t;
    }
};
