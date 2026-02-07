class Solution {
public:
    int solve(int n, vector<int>& t){
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(t[n] != -1) return t[n];

        return t[n] = solve(n-1, t) + solve(n-2, t);
    }
    int climbStairs(int n) {
        if(n<0)
            return 0;
        vector<int> t(n+1, -1);

        return solve(n, t);
    }
};