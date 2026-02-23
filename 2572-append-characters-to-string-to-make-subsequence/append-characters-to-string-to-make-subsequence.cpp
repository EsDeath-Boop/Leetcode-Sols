class Solution {
public:
    int appendCharacters(string s, string t) {
        int j =0;
        int n = t.length();

        for(char c : s){
            if(j <= n && c == t[j]){
                j++;
            }
        }
        return n - j;
    }
};