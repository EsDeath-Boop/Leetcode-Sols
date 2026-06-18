class Solution {
public:
    double angleClock(int h, int m) {
        return min(fabs(30.0*(h%12)-5.5*m), 360.0-fabs(30.0*(h%12)-5.5*m));
    }
};