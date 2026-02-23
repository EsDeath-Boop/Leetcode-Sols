class Solution {
public:
    int solve(vector<int>& jobDifficulty, int d, int idx, int n, vector<vector<int>>& t){

        if(t[idx][d] != -1)
            return t[idx][d];
        
        if(d==1){
            int maxD = jobDifficulty[idx];

            for(int i = idx; i < n; i++){
                maxD = max(jobDifficulty[i], maxD);
            }
            return maxD;
        }

        int maxD = jobDifficulty[idx];
        int finalRes = INT_MAX;

        for(int i = idx; i <= n - d; i++){
            maxD = max(maxD, jobDifficulty[i]);
            int result = maxD + solve(jobDifficulty, d-1, i+1, n, t);
            finalRes = min(finalRes, result);
        }

        return t[idx][d] = finalRes;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> t(n+1, vector<int>(d+1, -1));
        if(n < d)  
            return -1;

        return solve(jobDifficulty, d, 0, n, t);
    }
};