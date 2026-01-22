auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0;
        for(string s : bank ){
            int count = 0;
            for(char c : s){
                if(c == '1'){
                    count++;
                }
            }
            if(count != 0 ){
                curr+= (prev * count);
                prev = count;

            }
        }
        return curr;
    }
};