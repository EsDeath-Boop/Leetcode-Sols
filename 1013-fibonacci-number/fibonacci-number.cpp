class Solution {
public:

    // int solve(int n , vector<int>& t){
    //     if(n <= 1)
    //         return n;

    //     if(t[n] != -1){
    //         return t[n];
    //     }

    //     return t[n] = solve(n- 1, t) + solve(n-2, t);
    //     }
    // int fib(int n) {
    //     if (n == 0) return 0;
    //     if (n == 1) return 1;

    //     vector<int> t(n+1, -1);
    //     return solve(n, t);
    // }

    int fib(int n){
        // if(n <= 1)
        //     return n;

        // vector<int> t(n+1, -1);
        // t[0] = 0;
        // t[1] =1;

        // for(int i = 2; i <= n; i++){
        //     t[i] = t[i-1] + t[i-2];
        // }
        // return t[n];

        if(n <= 1)
            return n;
        int c;
        int a = 0;
        int b =1;

        for(int i = 1; i <n ; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
