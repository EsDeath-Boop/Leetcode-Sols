class Solution {
public: 
    using ll = long long;
    long long sumAndMultiply(int n) {
        ll ans = 0;
        ll sum = 0;

        for(char c : to_string(n)){
            if(c != '0'){
                ans = ans * 10 + c - '0';
                sum += c-'0';
            }
        }

        return ans * sum;
    }
};