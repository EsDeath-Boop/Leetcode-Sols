class Solution {
public:
    int check(vector<vector<int>>& mat, int m, int n, int row, int col){
        int rowCount = 0, colCount = 0;

        for(int j = 0; j < n; j++){
            if(mat[row][j] == 1)
                rowCount++;
        }

        for(int i = 0; i < m; i++){
            if(mat[i][col] == 1)
                colCount++;
        }

        if(rowCount == 1 && colCount == 1)
            return 1;

        return 0;
    }

    int solve(int m, int n, vector<vector<int>>& mat){
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && check(mat, m, n, i, j)){
                    count++;
                }
            }
        }

        return count;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        return solve(m, n, mat);
    }
};