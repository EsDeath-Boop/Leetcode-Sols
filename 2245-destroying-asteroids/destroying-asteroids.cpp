class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for(auto &x : arr){
            if(mass < x)
                return false;

            mass += x;
        }
        return true;
    }
};