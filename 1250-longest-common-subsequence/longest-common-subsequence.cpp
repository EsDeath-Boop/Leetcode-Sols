class Solution {
public:
    int m, n;

    int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& t){

        if(i >= n || j >= m)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];
        
        if(text1[i] == text2[j])
            return t[i][j] = 1 + solve(text1, text2, i+1, j+1, t);
        else
            return t[i][j] = max(solve(text1, text2, i, j+1, t), solve(text1, text2, i+1, j, t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        vector<vector<int>> t(1001, vector<int>(1001, -1));
        return solve(text1, text2, 0, 0, t);
    }
};