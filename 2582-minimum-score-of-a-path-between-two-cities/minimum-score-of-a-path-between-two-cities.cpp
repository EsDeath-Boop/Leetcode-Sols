class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& vis, int u, int& ans){
        vis[u] = true;

        for(auto &temp : adj[u]){
            int v = temp.first;
            int d = temp.second;

            ans = min(d, ans);

            if(!vis[v]){
                dfs(adj, vis, v, ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto &e : roads){
            int u = e[0];
            int v = e[1];
            int d = e[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n, false);

        int ans = INT_MAX;

        dfs(adj, vis, 1, ans);

        return ans;

    }
};