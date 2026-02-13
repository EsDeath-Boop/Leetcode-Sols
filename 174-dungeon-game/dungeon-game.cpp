class Solution {
public: 
    int helper(int i, int j, int n, int m, vector<vector<int>>& dungeon, vector<vector<int>>& t){
        if( i >= n || j >= m){
            return INT_MAX;
        }
        if(t[i][j] != -1)
            return t[i][j];

        if( i == n-1 && j == m -1){
            return t[i][j] = max(1, 1-dungeon[i][j]);
        }

        int right = helper(i, j +1, n, m, dungeon, t);
        int down = helper(i+1, j, n, m, dungeon, t);

        int health = min(right, down);

        return  t[i][j] = max(1, health - dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        return helper(0, 0, n, m, dungeon, t);
    }
};