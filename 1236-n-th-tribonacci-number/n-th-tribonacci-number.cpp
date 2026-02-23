class Solution {
public:
    // int solve(int n, vector<int>& t){
    //     if(n == 0) return 0;
    //     if(n == 1) return 1;
    //     if(n == 2) return 1;

    //     if(t[n] != -1){
    //         return t[n];
    //     }

    //     t[0] = 0;
    //     t[1] =1;
    //     t[2] = 1;

    //     for(int i = 3; i <= n; i++){
    //         t[i] = t[i-1] + t[i-2] + t[i-3];
    //     }
    
    //     return t[n];
    // }
    // int tribonacci(int n) {
    //     vector<int> t(n+1, -1);
    //     return solve(n, t);
    // }
    int solve(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int prev1 = 1, prev2 = 1, prev3 = 0, curr = 0;

        for(int i = 3 ; i <= n; i++){
            curr = prev1 + prev2 + prev3;

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int tribonacci(int n) {
        // vector<int> t(n+1, -1);
        return solve(n);
    }
};