class Solution {
public:
    
    bool solve(int i, int j, string s, string p, vector<vector<int>>& t){
        if(p.length() == j){
            return (s.length() == i);
        }

        bool firstMatched = false;

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(i < s.length() && (p[j] == s[i] || p[j] == '.')){
            firstMatched = true;
        }
        if(j+1 < p.length() && p[j+1] == '*'){
            bool notTake = solve(i, j+2, s, p, t);
            bool take = (firstMatched && solve(i+1, j, s, p, t));

            return t[i][j] = notTake || take;
        }
        
         return t[i][j] = firstMatched && solve(i+1, j+1, s, p, t);
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> t(21, vector<int> (21, -1));
        return solve(0, 0, s, p, t);
    }
};