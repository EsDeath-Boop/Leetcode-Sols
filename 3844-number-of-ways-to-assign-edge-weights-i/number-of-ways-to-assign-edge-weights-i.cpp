class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;

    ll pow(ll depth, ll exp){
        if(exp == 0)
            return 1;

        ll half = pow(depth, exp/2);

        ll ans = (half * half) % M;

        if(exp % 2 == 1){
            ans = (ans * depth) % M;
        }
        return ans;
    }

    int dfs(vector<vector<int>>& adj, int u, int par) {
        int count = 0;

        for (int v : adj[u]) {
            if (v == par) continue;

            count = max(count, 1 + dfs(adj, v, u));
        }

        return count;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth =  dfs(adj, 1, -1);

        return pow(2, depth-1);
    }
};