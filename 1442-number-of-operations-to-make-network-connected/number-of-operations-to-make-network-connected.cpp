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
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n- 1) 
            return -1;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            Union(u, v, parent, rank);
        }
        int components = 0;

        for(int i =0; i <= n-1; i++){
            if(find(i, parent) == i)
                components++;
        }
        return components-1;
    }
};