class Solution {
public: 
    int solve(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& t){
        if(i == m-1 && j == n-1)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(obstacleGrid[i][j] == 1)
            return 0;
        
        int down = 0;
        int right = 0;
        
        if(i < m -1 ){
            down =solve(i+1, j, m, n, obstacleGrid, t);
        }

        if(j < n -1){
            right = solve(i, j+1, m, n, obstacleGrid, t);
        }

        return t[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        return solve(0, 0, m, n, obstacleGrid, t);
    }
};