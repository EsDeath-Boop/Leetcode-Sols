class Solution {
public:

    // memoization

    // int solve(int r, int c, int m, int n, vector<vector<int>>& t){
    //     if(r == m -1 && c == n - 1)
    //         return 1;
    //     if(t[r][c] != -1)
    //         return t[r][c];
        
    //     int down = 0;
    //     int right = 0;

    //     int prev1 = 0;
    //     int prev2
    //     if(r < m - 1){
    //         down = solve(r + 1, c, m, n, t);
    //     }
    //     if(c < n -1){
    //         right = solve(r, c+1, m, n, t);
    //     }
    //     return t[r][c] =  down + right;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        // return solve(0, 0, m, n, t);
        // t[0][0] = 0;
        for(int i = 0; i < m; i++)
            t[i][0] = 1;

        for(int i =0;i < n; i++){
            t[0][i] = 1;
        }

        for(int i = 1;i < m;i++){
            for(int j =1; j < n; j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};