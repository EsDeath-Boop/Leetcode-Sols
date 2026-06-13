class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

    bool poss(vector<vector<int>> &grid, int i, int j, int n, int t, vector<vector<bool>> &visited){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] > t || visited[i][j] == true ){
            return false;   
        }

        visited[i][j] = true;

        if(i == n-1 && j == n-1)    return true;

        for(auto & dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(poss(grid, i_, j_, n, t, visited)){
                return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int low = grid[0][0];
        int high = n*n - 1;
        int res = 0;

        while(low <= high){
            int mid = low +  (high - low) / 2;

            vector<vector<bool>> visited(n, vector<bool>( n, false));
            if(poss(grid, 0, 0, n, mid, visited)){
                res = mid;
                high =  mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};