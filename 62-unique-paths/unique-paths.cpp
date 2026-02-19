class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& t){
        if(r == m -1 && c == n - 1)
            return 1;
        if(t[r][c] != -1)
            return t[r][c];
        
        int down = 0;
        int right = 0;
        if(r < m - 1){
            down = solve(r + 1, c, m, n, t);
        }
        if(c < n -1){
            right = solve(r, c+1, m, n, t);
        }
        return t[r][c] =  down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        return solve(0, 0, m, n, t);
    }
};