class Solution {
public:
    bool isGood(int n){
        bool ch = false;

        while(n > 0){
            int d = n % 10;

            if(d == 3 || d == 4 || d == 7)
                return false;

            if(d == 2 || d == 5 || d == 6 || d == 9)
                ch = true;

            n /= 10;
        }
        return ch;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 0; i <= n; i++){
            if(isGood(i))
                count++;
        }
        return count;
    }
};