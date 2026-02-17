class Solution {
public:
    bool solve(string s, string p){
        if(p.length() == 0){
            return (s.length() == 0);
        }
        bool firstMatched = false;

        if(s.length() > 0 && (p[0] == s[0] || p[0] == '.')){
            firstMatched = true;
        }
        if(p[1] == '*'){
            bool notTake = solve(s, p.substr(2));
            bool take = (firstMatched && solve(s.substr(1), p));

            return notTake || take;
        }
        
         return firstMatched && solve(s.substr(1), p.substr(1));
    }
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};