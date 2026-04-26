class Solution {
public:
    bool dfs(int i, int j, int pi, int pj, char ch,
             vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
                continue;

            if (grid[ni][nj] != ch)
                continue;

            if (!vis[ni][nj]) {
                if (dfs(ni, nj, i, j, ch, grid, vis))
                    return true;
            }
            else if (ni != pi || nj != pj) {
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid, vis))
                        return true;
                }
            }
        }
        return false;
    }
};