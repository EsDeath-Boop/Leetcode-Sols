class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.length();

        vector<int> temp(3, 0);

        int i = 0, j  = 0;

        while(j < n){
            char c = s[j];

            temp[c -'a']++;

            while(temp[0] > 0 && temp[1] > 0 && temp[2] > 0){
                ans += (n-j);

                temp[s[i] - 'a']--;
                i++; 
            }
            j++;
        }
        return ans;
    }
};