class Solution {
public:
    using ll = long long;

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

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];

            Union(u, v, parent, rank);  
        }

        unordered_map<int, ll> mp;

        for(int i = 0; i < n; i++){
            int par_i = find(i, parent);
            mp[par_i]++;
        }

        ll res = 0;
        ll remaining = n;

        for(auto &it : mp){
            ll size = it.second;
            res += size * (remaining - size);
            remaining -= size;
        }

        return res;
    }
};
