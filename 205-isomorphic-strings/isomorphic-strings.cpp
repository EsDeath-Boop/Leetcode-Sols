class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpS;
        unordered_map<char, char> mpT;

        int n = s.length();

        if(s.length() != t.length())
            return false;

        for(int i = 0; i < n; i++){
            char c1 = s[i];
            char c2 = t[i];

            if(mpS.find(c1) != mpS.end() && mpS[c1] != c2 || mpT.find(c2) != mpT.end() && mpT[c2] != c1)
                return false;

            mpS[c1] = c2;
            mpT[c2] = c1;
        }
        return true;
    }
};