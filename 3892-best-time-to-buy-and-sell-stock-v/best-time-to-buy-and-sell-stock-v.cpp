class Solution {
public:
    long long solve(vector<int>& prices, int k, int i, int CASE, int n, vector<vector<vector<long long>>>& t){
        if(i >= n){
            if(CASE == 0) return 0;
            return INT_MIN;
        }

        if(t[i][k][CASE] != -1){
            return t[i][k][CASE];
        }

        long long take = 0;
        long long skip = 0;

        skip = solve(prices, k, i+1, CASE, n, t);

        if(k > 0){
            if(CASE == 1){ // sell
                take = prices[i] + solve(prices, k - 1, i+1, 0, n, t);
            } else if(CASE == 2){ // buy
                take = -prices[i] + solve(prices, k-1, i+1, 0, n, t);
            }else{
                take = max(prices[i] + solve(prices, k, i+1, 2, n, t), -prices[i] + solve(prices, k, i+1, 1, n, t));
            }
        }
        return t[i][k][CASE] = max(take, skip);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> t(n+1, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        return solve(prices, k, 0, 0, n, t);
    }
};