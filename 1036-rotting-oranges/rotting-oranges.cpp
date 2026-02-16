class Solution {
public:
    typedef pair<int, int> p;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0,1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<p> q;
        int fresh = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    // q.push({i, j});
                    fresh++;
                }
            }
        }
        if(fresh == 0)
            return 0;

        int minutes = 0;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                p curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for(vector<int> &dir : directions){
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];

                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1){
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? (minutes-1) : -1;
    }
};