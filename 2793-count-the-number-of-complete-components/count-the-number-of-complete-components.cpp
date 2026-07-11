class Solution {
public:
    void hasCycle(vector<vector<int>>& adj, vector<bool>& vis, int& nodes,
                  int& degreeSum, int u) {
        vis[u] = true;

        nodes++;
        degreeSum += adj[u].size();

        for (auto& child : adj[u]) {
            if (!vis[child])
                hasCycle(adj, vis, nodes, degreeSum, child);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n, -1);
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int degreeSum = 0;

                hasCycle(adj, vis, nodes, degreeSum, i);

                int edges = degreeSum / 2;

                if (edges == nodes * (nodes - 1) / 2)
                    count++;
            }
        }

        return count;
    }
};