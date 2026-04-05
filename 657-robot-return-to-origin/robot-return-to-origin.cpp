class Solution {
public:
    bool judgeCircle(string moves) {
        int ver = 0;
        int hor = 0;

        for(char c : moves){
            if(c == 'U') ver++;
            else if(c == 'D') ver--;
            else if(c == 'R') hor++;
            else if(c == 'L') hor--;
        }
        if(ver == 0 && hor == 0) return 1;
        return 0;
    }
};