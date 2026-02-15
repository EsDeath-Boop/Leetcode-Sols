class Solution {
public:
    int find(int i, vector<int>& parent){
        if(parent[i] == i)
            return i;

        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_par = find(x, parent);
        int y_par = find(y, parent);

        if(x_par == y_par) return;
        if(rank[x_par] > rank[y_par])
            parent[y_par] = x_par;
        else if(rank[y_par] > rank[x_par])
            parent[x_par] = y_par;
        else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for(int i =0; i < 26;i++){
            parent[i] = i;
        }
        vector<int> rank(26, 0);

        for(string &s : equations){
            if(s[1] == '='){
                Union(s[0]-'a',s[3]-'a', parent, rank);
            }
        }

        for(string &s : equations){
            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];

                int first_par = find(first - 'a', parent);
                int sec_par = find(second - 'a', parent);

                if(first_par == sec_par){
                    return false;
                }
            }
        }
        return true;
    }
};  