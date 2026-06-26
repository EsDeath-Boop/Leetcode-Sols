class Solution {
public:

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        q.push({0, 0, k});

        int i = 0, j = 0;
        vector<vector<vector<bool>>> vis(n+1, vector<vector<bool>> (m+1, vector<bool> (m*n+1, false)));
        // vis[0][0][k] = true;
        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                vector<int> temp = q.front();
                q.pop();

                int ci = temp[0];
                int cj = temp[1];
                int obs = temp[2];

                if(ci == n-1 && cj == m-1)
                    return steps;

                for(auto &dir : directions){
                    int i_ = ci + dir[0];
                    int j_ = cj + dir[1];

                    if(i_ >= n || i_ < 0 || j_ >= m || j_ < 0)    
                        continue;

                    if(grid[i_][j_] == 0 && !vis[i_][j_][obs]){
                        q.push({i_, j_, obs});
                        vis[i_][j_][obs] = true;

                    }else if(grid[i_][j_] == 1 && obs > 0 && !vis[i_][j_][obs-1]){
                        q.push({i_, j_, obs -1});
                        vis[i_][j_][obs-1] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};